/*
** EPITECH PROJECT, 2021
** 4001.hpp
** File description:
** 4001hpp
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4001 : public nts::AComponent
    {
    public:
        C4001(std::string = "4001");
        ~C4001();
        void dump(void) const;
        std::vector<nts::Pin *> getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
