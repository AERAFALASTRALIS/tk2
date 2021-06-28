/*
** EPITECH PROJECT, 2021
** agate
** File description:
** agate
*/

#ifndef AGATE_HPP_
#define AGATE_HPP_

#include <vector>
#include "Pin.hpp"

namespace nts
{
    class AGate
    {
    public:
        AGate(Pin *output = nullptr);
        virtual ~AGate() {};
        virtual nts::Tristate compute() = 0;
        virtual bool preventLoop(nts::AGate *, int) const = 0;
        void setOutput(Pin *);
        void toggle();
    protected:
        Pin *output1;
        bool open;
    };
}

#endif
