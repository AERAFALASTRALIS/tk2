/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#ifndef GATELOGGER_HPP_
#define GATELOGGER_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateLogger: public AGate
    {
    public:
        GateLogger(std::vector<Pin *>, Pin *, Pin *);
        ~GateLogger();
    public:
        bool preventLoop(AGate *gate, int) const;
        nts::Tristate compute();
    private:
        std::vector<Pin *> bits;
        Pin *clock;
        Pin *inhibit;
    };
}

#endif 
