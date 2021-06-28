/*
** EPITECH PROJECT, 2021
** 4040
** File description:
** 4040
*/

#include "4040.hpp"
#include "GateCounter.hpp"

nts::C4040::C4040(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;
    std::vector<Pin *> outputs;

    for (int i = 1; i < 17; i++) {
        if (i == 10 || i == 11)
	        pin = new Pin(nts::INPUT);
        else if (i == 8 || i == 16)
        	pin = new Pin(nts::OTHER);
        else
        	pin = new Pin(nts::OUTPUT);
        this->pins.push_back(pin);
    }
    outputs.push_back(this->pins[8]);
    outputs.push_back(this->pins[6]);
    outputs.push_back(this->pins[5]);
    outputs.push_back(this->pins[4]);
    outputs.push_back(this->pins[2]);
    outputs.push_back(this->pins[1]);
    outputs.push_back(this->pins[3]);
    outputs.push_back(this->pins[12]);
    outputs.push_back(this->pins[11]);
    outputs.push_back(this->pins[13]);
    outputs.push_back(this->pins[14]);
    outputs.push_back(this->pins[0]);
    this->gates.push_back(new GateCounter(this->pins[8], outputs, this->pins[9], this->pins[10]));
}

nts::C4040::~C4040()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::C4040::dump(void) const
{
    std::cout << "4040 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C4040::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
