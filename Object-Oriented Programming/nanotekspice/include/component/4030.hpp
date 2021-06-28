/*
** EPITECH PROJECT, 2021
** 4030
** File description:
** 4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4030 : public nts::AComponent
    {
    public:
        C4030(std::string = "4030");
        ~C4030();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
