/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATENAND_HPP_
#define GATENAND_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateNand: public AGate
    {
    public:
        GateNand(Pin * = nullptr, Pin * = nullptr, Pin * = nullptr);
        ~GateNand();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        Pin *input1;
        Pin *input2;
    };
}

#endif 
