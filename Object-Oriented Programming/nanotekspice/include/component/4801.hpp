/*
** EPITECH PROJECT, 2021
** 4801
** File description:
** 4801
*/

#ifndef C4801_HPP_
#define C4801_HPP_

#include "AComponent.hpp"

namespace nts
{
    class C4801 : public nts::AComponent
    {
    public:
        C4801(std::string = "4801");
        ~C4801();
        void dump(void) const;
        std::vector<nts::Pin *>	getPins() const;
        void openGates();
    private:
        std::vector<AGate *>gates;
    };
}

#endif
