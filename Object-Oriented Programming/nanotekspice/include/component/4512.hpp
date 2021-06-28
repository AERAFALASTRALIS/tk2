/*
** EPITECH PROJECT, 2021
** 4512
** File description:
** 4512
*/

#ifndef C4512_HPP_
#define C4512_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4512 : public nts::AComponent
    {
    public:
        C4512(std::string = "4512");
        ~C4512();
    public:
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
