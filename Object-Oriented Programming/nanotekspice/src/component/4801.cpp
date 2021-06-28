/*
** EPITECH PROJECT, 2021
** 4801
** File description:
** 4801
*/

#include "4801.hpp"

nts::C4801::C4801(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 1; i++) {
        if (i == 1 || i == 2 || i == 3 || i == 21 || i == 22 || i == 23)
	        pin = new Pin(nts::INPUT);
        else if (i == 12 || i == 24)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::OUTPUT);
        this->pins.push_back(pin);
    }
    //this->gates.push_back(new Gate());
}

nts::C4801::~C4801()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4801::dump(void) const
{
    std::cout << "4801 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4801::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
