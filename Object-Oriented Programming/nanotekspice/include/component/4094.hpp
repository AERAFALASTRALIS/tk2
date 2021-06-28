/*
** EPITECH PROJECT, 2021
** 4094
** File description:
** 4094
*/

#ifndef C4094_HPP_
#define C4094_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4094 : public nts::AComponent
    {
    public:
        C4094(std::string = "4094");
        ~C4094();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
