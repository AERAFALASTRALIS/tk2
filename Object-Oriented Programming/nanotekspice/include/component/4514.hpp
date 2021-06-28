/*
** EPITECH PROJECT, 2021
** 4514
** File description:
** 4514
*/

#ifndef C4514_HPP_
#define C4514_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4514 : public nts::AComponent
    {
    public:
        C4514(std::string = "4514");
        ~C4514();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
