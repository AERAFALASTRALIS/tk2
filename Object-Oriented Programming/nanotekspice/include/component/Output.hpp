/*
** EPITECH PROJECT, 2021
** Output
** File description:
** Output
*/

#ifndef OUPUT_HPP_
#define OUPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Output: public AComponent
    {
    public:
        Output(std::string = "Output");
        ~Output();
        nts::Tristate compute(size_t pin_num_this = 1);
        void dump(void) const;
        void openGates();
    private:
        AGate *gate;
    };
}

#endif
