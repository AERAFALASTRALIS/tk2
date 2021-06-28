/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATENOR_HPP_
#define GATENOR_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateNor: public AGate
    {
    public:
        GateNor(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateNor();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
    };
}

#endif
