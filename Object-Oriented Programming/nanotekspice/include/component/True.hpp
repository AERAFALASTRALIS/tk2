/*
** EPITECH PROJECT, 2021
** True
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "AComponent.hpp"

namespace nts
{
    class True: public AComponent
    {
    public:
        True(std::string = "True");
        ~True();
    public:
        nts::Tristate compute(size_t pin_num_this = 1);
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        AGate *gate;
    };
}

#endif
