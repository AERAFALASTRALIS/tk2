/*
** EPITECH PROJECT, 2021
** Input
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Input: public AComponent
    {
    public:
        Input(std::string = "Input", nts::Tristate = nts::UNDEFINED);
        ~Input();
        nts::Tristate compute(size_t pin_num_this = 1);
        void dump(void) const;
        void setState(nts::Tristate);
        void openGates();
    private:
        AGate *gate;
    };
}

#endif
