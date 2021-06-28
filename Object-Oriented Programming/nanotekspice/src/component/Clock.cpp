/*
** EPITECH PROJECT, 2021
** clock
** File description:
** clock
*/

#include "Clock.hpp"
#include "GateOutput.hpp"

nts::Clock::Clock(std::string name, nts::Tristate value) : AComponent(name, nts::BASIC_CLOCK)
{
    this->pins.push_back(new Pin(nts::OUTPUT));
    this->pins[0]->setState(value);
    this->gate = new GateOutput(this->pins[0]);
}

nts::Clock::~Clock()
{
    for (std::vector<nts::Pin *>::iterator it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    delete gate;
}

nts::Tristate nts::Clock::compute(size_t pin_num_this)
{
    if (pin_num_this != 1)
    	return (nts::UNDEFINED);
    return (this->pins[0]->getState());
}

void nts::Clock::dump(void) const
{
    std::cout << "Clock ->\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::Clock::tick()
{
    nts::Tristate state;

    state = this->pins[0]->getState();
    if (state == nts::TRUE)
		this->pins[0]->setState(nts::FALSE);
    else if (!state)
    	this->pins[0]->setState(nts::TRUE);
}

void nts::Clock::openGates()
{
    this->gate->toggle();
}
