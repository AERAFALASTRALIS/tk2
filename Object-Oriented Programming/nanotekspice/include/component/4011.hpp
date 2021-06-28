/*
** EPITECH PROJECT, 2021
** 4011
** File description:
** 4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4011 : public nts::AComponent
    {
    public:
        C4011(std::string = "4011");
        ~C4011();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
