/*
** EPITECH PROJECT, 2021
** 4094
** File description:
** 4094
*/

#include "4094.hpp"

nts::C4094::C4094(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 1; i++) {
        if (i == 3 || i == 4 || i == 10 || i == 11)
	        pin = new Pin(nts::OUTPUT);
        else if (i == 7 || i == 14)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    //this->gates.push_back(new Gate());
}

nts::C4094::~C4094()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4094::dump(void) const
{
    std::cout << "4094 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4094::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}

