/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEBIN4TODEC16_HPP_
#define GATEBIN4TODEC16_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateBin4ToDec16: public AGate
    {
    public:
        GateBin4ToDec16(Pin *, std::vector<Pin *>, Pin *, Pin *, Pin *, Pin *, Pin *, Pin *);
        ~GateBin4ToDec16();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        std::vector<Pin *> outputs;
        Pin *inhibit;
        Pin *inputA;
        Pin *inputB;
        Pin *inputC;
        Pin *inputD;
        Pin *strobe;
    };
}

#endif
