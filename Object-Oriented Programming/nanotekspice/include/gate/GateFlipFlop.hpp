/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEFLIPFLOP_HPP_
#define GATEFLIPFLOP_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateFlipFlop: public AGate
    {
    public:
        GateFlipFlop(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr, Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateFlipFlop();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();

    private:
        Pin *clock;
        Pin *reset;
        Pin *data;
        Pin *set;
        Pin *output2;
    };
}

#endif
