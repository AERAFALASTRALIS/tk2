/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATESUM_HPP_
#define GATESUM_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateSum: public AGate
    {
    public:
        GateSum(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateSum();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
        Pin *carryIn;
        Pin *carryOut;
    };
}

#endif
