/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEOR_HPP_
#define GATEOR_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateOr: public AGate
    {
    public:
        GateOr(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateOr();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
    };
}

#endif
