/*
** EPITECH PROJECT, 2021
** acomponent
** File description:
** acomponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#define TL_L "This configuration lead to an infinite loop"
#define TC_P "This component doesn't have enough pins"
#define TC_X "that component doesn't have enough pins"
#define CL_T "Can't link two pins of the same type"
#define TP_O "That pin isn't an input nor an output"
#define TP_I "This pin isn't an input nor an output"


#include <vector>
#include <fstream>
#include "IComponent.hpp"
#include "AGate.hpp"
#include "Pin.hpp"

namespace nts
{
    enum Component_type
    {
        CHIPSET = 1,
        BASIC_INPUT = 2,
        BASIC_OUTPUT = 3,
        BASIC_CLOCK = 4,
        BASIC = 5
    };
    class AComponent: public IComponent
    {
    public:
        AComponent(std::string, nts::Component_type);
        virtual ~AComponent() {};
        nts::Tristate compute(size_t pin = 1);
        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        void printState() const;
        std::vector<nts::Pin *> getPins() const;
        std::string getName() const;
        Component_type getType() const;
        virtual void openGates() = 0;
    protected:
        std::string name;
        Component_type type;
        std::vector<nts::Pin *>	pins;
    };
}

#endif
