/*
** EPITECH PROJECT, 2021
** 4013
** File description:
** 4013
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4013 : public nts::AComponent
    {
    public:
        C4013(std::string = "4013");
        ~C4013();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
