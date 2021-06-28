/*
** EPITECH PROJECT, 2021
** gateand
** File description:
** gateand
*/

#ifndef GATEOR_HPP_
#define GATEOR_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateAnd: public AGate
    {
    public:
        GateAnd(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateAnd();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
    };
}

#endif
