/*
** EPITECH PROJECT, 2021
** 4040
** File description:
** 4040
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4040 : public nts::AComponent
    {
    public:
        C4040(std::string = "4040");
        ~C4040();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
