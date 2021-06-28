/*
** EPITECH PROJECT, 2021
** 400_
** File description:
** 4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class C4008 : public nts::AComponent
    {
    public:
        C4008(std::string = "4008");
        ~C4008();
        void dump(void) const;
        std::vector<nts::Pin *> getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
