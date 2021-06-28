/*
** EPITECH PROJECT, 2021
** 2716
** File description:
** 2716
*/

#ifndef C2716_HPP_
#define C2716_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C2716 : public nts::AComponent
    {
    public:
        C2716(std::string = "2716");
        ~C2716();
        void dump(void) const;
        std::vector<nts::Pin *> getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
