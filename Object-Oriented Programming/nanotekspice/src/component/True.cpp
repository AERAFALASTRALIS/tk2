/*
** EPITECH PROJECT, 2021
** true
** File description:
** true
*/

#include "True.hpp"
#include "GateOutput.hpp"

nts::True::True(std::string name) : AComponent(name, nts::BASIC)
{
    this->pins.push_back(new Pin(nts::OUTPUT));
    this->pins[0]->setState(nts::TRUE);
    this->gate = new GateOutput(this->pins[0]);
}

nts::True::~True()
{
    for (std::vector<nts::Pin *>::iterator it = this->pins.begin();
    	it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    delete gate;
}

nts::Tristate nts::True::compute(size_t pin_num_this)
{
    if (pin_num_this != 1)
    	return (nts::UNDEFINED);
    return (this->pins[0]->getState());
}

void nts::True::dump(void) const
{
    std::cout << "True ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::True::openGates()
{
    this->gate->toggle();
}
