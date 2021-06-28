/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEOUTPUT_HPP_
#define GATEOUTPUT_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateOutput: public AGate
    {
    public:
        GateOutput(Pin * = nullptr);
        ~GateOutput();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    };
}

#endif
