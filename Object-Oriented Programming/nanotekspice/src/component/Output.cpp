/*
** EPITECH PROJECT, 2021
** Output
** File description:
** Output
*/

#include "Output.hpp"
#include "GateInput.hpp"

nts::Output::Output(std::string name) : AComponent(name, nts::BASIC_OUTPUT)
{
    this->pins.push_back(new Pin(nts::INPUT));
    this->gate = new GateInput(NULL, this->pins[0]);
}

nts::Output::~Output()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    delete gate;
}

nts::Tristate nts::Output::compute(size_t pin_num_this)
{
    if (pin_num_this != 1)
    	return (nts::UNDEFINED);
    return (this->gate->compute());
}

void nts::Output::dump(void) const
{
    std::cout << "Output ->\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::Output::openGates()
{
    this->gate->toggle();
}
