/*
** EPITECH PROJECT, 2021
** 4069
** File description:
** 4069
*/

#include "4069.hpp"
#include "GateNot.hpp"

nts::C4069::C4069(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 15; i++) {
        if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12)
	        pin = new Pin(nts::OUTPUT);
        else if (i == 7 || i == 14)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    this->gates.push_back(new GateNot(this->pins[1], this->pins[0]));
    this->gates.push_back(new GateNot(this->pins[3], this->pins[2]));
    this->gates.push_back(new GateNot(this->pins[5], this->pins[4]));
    this->gates.push_back(new GateNot(this->pins[7], this->pins[8]));
    this->gates.push_back(new GateNot(this->pins[9], this->pins[10]));
    this->gates.push_back(new GateNot(this->pins[11], this->pins[12]));
}

nts::C4069::~C4069()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4069::dump(void) const
{
    std::cout << "4069 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4069::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
