/*
** EPITECH PROJECT, 2021
** false
** File description:
** false
*/

#include "False.hpp"
#include "GateOutput.hpp"

nts::False::False(std::string name) : AComponent(name, nts::BASIC)
{
    this->pins.push_back(new Pin(nts::OUTPUT));
    this->pins[0]->setState(nts::FALSE);
    this->gate = new GateOutput(this->pins[0]);
}

nts::False::~False()
{
    for (std::vector<nts::Pin*>::iterator it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    delete gate;
}

nts::Tristate nts::False::compute(size_t pin_num_this)
{
    if (pin_num_this != 1)
    	return (nts::UNDEFINED);
    return (this->pins[0]->getState());
}

void nts::False::dump(void) const
{
    std::cout << "False ->\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::False::openGates()
{
    this->gate->toggle();
}
