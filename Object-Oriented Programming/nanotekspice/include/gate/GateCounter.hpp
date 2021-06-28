/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATECOUNTER_HPP_
#define GATECOUNTER_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateCounter: public AGate
    {
    public:
        GateCounter(Pin *, std::vector<Pin *>, Pin *, Pin *);
        ~GateCounter();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        std::vector<Pin *> outputs;
        Pin *clock;
        Pin *reset;
    };
}

#endif
