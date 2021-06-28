/*
** EPITECH PROJECT, 2021
** Clock
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Clock: public AComponent
    {
    public:
        Clock(std::string = "Clock", nts::Tristate = nts::UNDEFINED);
        ~Clock();
    public:
        nts::Tristate compute(size_t pin_num_this = 1);
        void dump(void) const;
        void tick();
        void openGates();
    private:
        AGate *gate;
    };
}

#endif
