/*
** EPITECH PROJECT, 2021
** 4514
** File description:
** 4514
*/

#include "4514.hpp"
#include "GateBin4ToDec16.hpp"

nts::C4514::C4514(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;
    std::vector<Pin *> outputs;

    for (int i = 1; i < 25; i++) {
        if (i == 1 || i == 2 || i == 3 || i == 21 || i == 22 || i == 23)
	        pin = new Pin(nts::INPUT);
        else if (i == 12 || i == 24)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::OUTPUT);
        this->pins.push_back(pin);
    }
    outputs.push_back(this->pins[10]);
    outputs.push_back(this->pins[8]);
    outputs.push_back(this->pins[9]);
    outputs.push_back(this->pins[7]);
    outputs.push_back(this->pins[6]);
    outputs.push_back(this->pins[5]);
    outputs.push_back(this->pins[4]);
    outputs.push_back(this->pins[3]);
    outputs.push_back(this->pins[17]);
    outputs.push_back(this->pins[16]);
    outputs.push_back(this->pins[19]);
    outputs.push_back(this->pins[18]);
    outputs.push_back(this->pins[13]);
    outputs.push_back(this->pins[12]);
    outputs.push_back(this->pins[15]);
    outputs.push_back(this->pins[14]);
    this->gates.push_back(new GateBin4ToDec16(this->pins[10], outputs, this->pins[22], this->pins[1], this->pins[2], this->pins[20], this->pins[21], this->pins[0]));
}

nts::C4514::~C4514()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4514::dump(void) const
{
    std::cout << "4514 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4514::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}

