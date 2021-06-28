/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATENOT_HPP_
#define GATENOT_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateNot: public AGate
    {
    public:
        GateNot(Pin * = nullptr, Pin * = nullptr);
        ~GateNot();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
    };
}

#endif
