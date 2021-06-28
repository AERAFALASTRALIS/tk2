/*
** EPITECH PROJECT, 2021
** 2716
** File description:
** 2716
*/

#include "2716.hpp"

nts::C2716::C2716(std::string name) : AComponent(name, nts::CHIPSET)
{
    nts::Pin *pin;

    for (int i = 1; i < 1; i++) {
        if (i)
            pin = new Pin(nts::OUTPUT);
        else if (i)
            pin = new Pin(nts::OTHER);
        else
            pin = new Pin(nts::INPUT);
        this->pins.push_back(pin);
    }
    //this->gates.push_back(new Gate());
}

nts::C2716::~C2716()
{
    for (auto it = this->pins.begin(); it!= this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}


void nts::C2716::dump(void) const
{
    std::cout << "4001 ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::C2716::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}
