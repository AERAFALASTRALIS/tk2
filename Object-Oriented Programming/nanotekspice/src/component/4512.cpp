/*
** EPITECH PROJECT, 2021
** 4512
** File description:
** 4512
*/

#include "4512.hpp"
#include "GateBin3ToDec8.hpp"

nts::C4512::C4512(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;
    std::vector<Pin *> outputs;

    for (int i = 1; i < 17; i++) {
        if (i == 10 || i == 11 || i == 12 || i == 13 || i == 15)
	        pin = new Pin(nts::INPUT);
        else if (i == 8 || i == 16)
        	pin = new Pin(nts::OTHER);
        else {
        	pin = new Pin(nts::OUTPUT);
            if (i != 14)
	            outputs.push_back(pin);
        }
        this->pins.push_back(pin);
    }
    this->gates.push_back(new GateBin3ToDec8(this->pins[13], outputs, this->pins[9], this->pins[10], this->pins[11], this->pins[12], this->pins[14]));
}

nts::C4512::~C4512()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4512::dump(void) const
{
    std::cout << "4512 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4512::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
