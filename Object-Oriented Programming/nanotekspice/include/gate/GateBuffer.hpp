/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEBUFFER_HPP_
#define GATEBUFFER_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateBuffer: public AGate
    {
    public:
        GateBuffer(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateBuffer();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *disableInput;
    };
}

#endif
