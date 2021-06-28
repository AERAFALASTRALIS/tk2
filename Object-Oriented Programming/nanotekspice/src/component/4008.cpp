/*
** EPITECH PROJECT, 2021
** 4008
** File description:
** 4008
*/

#include "4008.hpp"
#include "GateSum.hpp"

nts::C4008::C4008(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 17; i++) {
        if (i == 10 || i == 11 || i == 12 || i == 13 || i == 14)
            pin = new Pin(nts::OUTPUT);
        else if (i == 8 || i == 16)
            pin = new Pin(nts::OTHER);
        else
            pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    this->gates.push_back(new GateSum(this->pins[12], this->pins[14], this->pins[0], this->pins[8], this->pins[13]));
    this->gates.push_back(new GateSum(this->pins[11], this->pins[1], this->pins[2], this->pins[8], this->pins[13]));
    this->gates.push_back(new GateSum(this->pins[10], this->pins[3], this->pins[4], this->pins[8], this->pins[13]));
    this->gates.push_back(new GateSum(this->pins[9], this->pins[5], this->pins[6], this->pins[8], this->pins[13]));
}

nts::C4008::~C4008()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}


void nts::C4008::dump(void) const
{
    std::cout << "C4008 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4008::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
