/*
** EPITECH PROJECT, 2021
** 4017
** File description:
** 4017
*/

#ifndef C4017_HPP_
#define C4017_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4017 : public nts::AComponent
    {
    public:
        C4017(std::string = "4017");
        ~C4017();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
