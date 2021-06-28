/*
** EPITECH PROJECT, 2021
** 4013
** File description:
** 4013
*/

#include "4013.hpp"
#include "GateFlipFlop.hpp"

nts::C4013::C4013(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 15; i++) {
        if (i == 1 || i == 2 || i == 12 || i == 13)
	        pin = new Pin(nts::OUTPUT);
        else if (i == 7 || i == 14)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    this->gates.push_back(new GateFlipFlop(this->pins[0], this->pins[1], this->pins[2], this->pins[3], this->pins[4], this->pins[5]));
    this->gates.push_back(new GateFlipFlop(this->pins[11], this->pins[12], this->pins[7], this->pins[8], this->pins[9], this->pins[10]));
}

nts::C4013::~C4013()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4013::dump(void) const
{
    std::cout << "4013 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4013::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
