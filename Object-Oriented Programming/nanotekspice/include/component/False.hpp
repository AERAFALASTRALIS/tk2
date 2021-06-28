/*
** EPITECH PROJECT, 2021
** False
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "AComponent.hpp"

namespace nts
{
    class False: public AComponent
    {
    public:
        False(std::string = "False");
        ~False();
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
