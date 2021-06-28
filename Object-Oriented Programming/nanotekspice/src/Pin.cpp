/*
** EPITECH PROJECT, 2021
** pine
** File description:
** pine
*/

#include "Pin.hpp"

nts::Pin::Pin(nts::Pin_type type) : linked(NULL), pin_num(0), state(nts::UNDEFINED), type(type) {}

nts::Pin::~Pin() {}

void nts::Pin::setLinked(IComponent *linked)
{
    this->linked = linked;
}

nts::IComponent	*nts::Pin::getLinked() const
{
    return (this->linked);
}

void nts::Pin::setPin_num(size_t pin_num)
{
    this->pin_num = pin_num;
}

size_t nts::Pin::getPin_num() const
{
    return (this->pin_num);
}

void nts::Pin::setState(nts::Tristate state)
{
    this->state = state;
}

nts::Tristate nts::Pin::getState() const
{
    return (this->state);
}

void nts::Pin::setType(nts::Pin_type type)
{
    this->type = type;
}

nts::Pin_type nts::Pin::getType() const
{
    return (this->type);
}

void nts::Pin::setGate(AGate *gate)
{
    this->gate = gate;
}

nts::AGate *nts::Pin::getGate() const
{
    return (this->gate);
}
