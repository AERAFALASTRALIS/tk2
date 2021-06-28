/*
** EPITECH PROJECT, 2021
** pin
** File description:
** pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

namespace nts
{
    class AGate;
    enum Pin_type
    {
        INPUT = 1,
        OUTPUT = 2,
        OTHER = 3
    };
    class Pin
    {
    public:
        Pin(Pin_type);
        ~Pin();
        void setLinked(IComponent *);
        IComponent *getLinked() const;
        void setPin_num(size_t);
        size_t getPin_num() const;
        void setState(nts::Tristate);
        nts::Tristate getState() const;
        void setType(nts::Pin_type);
        nts::Pin_type getType() const;
        void setGate(AGate *gate);
        AGate *getGate() const;
    private:
        IComponent *linked;
        size_t pin_num;
        nts::Tristate state;
        nts::Pin_type type;
        AGate *gate;
    };
};

#endif
