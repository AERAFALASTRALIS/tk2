/*
** EPITECH PROJECT, 2021
** 4017
** File description:
** 4017
*/

#include "4017.hpp"

nts::C4017::C4017(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 16; i++) {
        if (i > 12)
	        pin = new Pin(nts::OUTPUT);
        else if (i != 8)
        	pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    //this->gates.push_back(new Gate());
}

nts::C4017::~C4017()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4017::dump(void) const
{
    std::cout << "4017 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4017::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}

