/*
** EPITECH PROJECT, 2021
** Input
** File description:
** Input
*/

#include "Input.hpp"
#include "GateOutput.hpp"

nts::Input::Input(std::string name, nts::Tristate value) : AComponent(name, nts::BASIC_INPUT)
{
    this->pins.push_back(new Pin(nts::OUTPUT));
    this->pins[0]->setState(value);
    this->gate = new GateOutput(this->pins[0]);
}

nts::Input::~Input()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    delete gate;
}

nts::Tristate nts::Input::compute(size_t pin_num_this)
{
    if (pin_num_this != 1)
    	return (nts::UNDEFINED);
    return (this->pins[0]->getState());
}

void nts::Input::setState(nts::Tristate value)
{
    this->pins[0]->setState(value);
}

void nts::Input::dump(void) const
{
    std::cout << "Input ->\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::Input::openGates()
{
    this->gate->toggle();
}
