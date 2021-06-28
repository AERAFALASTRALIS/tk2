/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATEBIN3TODEC8_HPP_
#define GATEBIN3TODEC8_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateBin3ToDec8: public AGate
    {
    public:
        GateBin3ToDec8(Pin *, std::vector<Pin *>, Pin *, Pin *, Pin *, Pin *, Pin *);
        ~GateBin3ToDec8();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        std::vector<Pin *> outputs;
        Pin *inhibit;
        Pin *inputA;
        Pin *inputB;
        Pin *inputC;
        Pin *inputOE;
    };
}

#endif 
