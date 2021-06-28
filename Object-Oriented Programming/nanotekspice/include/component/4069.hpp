/*
** EPITECH PROJECT, 2021
** 4069
** File description:
** 4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4069 : public nts::AComponent
    {
    public:
        C4069(std::string = "4069");
        ~C4069();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
