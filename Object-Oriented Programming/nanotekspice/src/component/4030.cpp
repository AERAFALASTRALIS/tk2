/*
** EPITECH PROJECT, 2021
** 4030
** File description:
** 4030
*/

#include "4030.hpp"
#include "GateXor.hpp"

nts::C4030::C4030(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 15; i++) {
        if (i == 3 || i == 4 || i == 10 || i == 11)
	        pin = new Pin(nts::OUTPUT);
        else if (i == 7 || i == 14)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    this->gates.push_back(new GateXor(this->pins[2], this->pins[0], this->pins[1]));
    this->gates.push_back(new GateXor(this->pins[3], this->pins[4], this->pins[5]));
    this->gates.push_back(new GateXor(this->pins[9], this->pins[7], this->pins[8]));
    this->gates.push_back(new GateXor(this->pins[10], this->pins[11], this->pins[12]));
}

nts::C4030::~C4030()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4030::dump(void) const
{
    std::cout << "4030 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4030::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
