/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEINPUT_HPP_
#define GATEINPUT_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateInput: public AGate
    {
    public:
        GateInput(Pin * = nullptr, Pin * = nullptr);
        ~GateInput();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
    };
}

#endif 
