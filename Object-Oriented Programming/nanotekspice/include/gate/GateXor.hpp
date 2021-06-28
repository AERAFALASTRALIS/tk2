/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEXOR_HPP_
#define GATEXOR_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateXor: public AGate
    {
    public:
        GateXor(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateXor();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
    };
}

#endif
