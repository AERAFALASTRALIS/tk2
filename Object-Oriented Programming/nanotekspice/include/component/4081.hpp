/*
** EPITECH PROJECT, 2021
** 4081
** File description:
** 4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4081 : public nts::AComponent
    {
    public:
        C4081(std::string = "4081");
        ~C4081();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
