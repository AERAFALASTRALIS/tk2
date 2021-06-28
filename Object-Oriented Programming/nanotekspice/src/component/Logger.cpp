/*
** EPITECH PROJECT, 2021
** logger
** File description:
** logger
*/

#include "Logger.hpp"

nts::Logger::Logger(std::string name) : AComponent(name, nts::BASIC_OUTPUT)
{
    nts::Pin *pin;

    for (int i = 1; i < 11; i++) {
	    pin = new Pin(nts::OUTPUT);
        this->pins.push_back(pin);
    }
    //this->gates.push_back(new Gate());
}

nts::Logger::~Logger()
{
    for (auto it = this->pins.begin(); it != this->pins.end(); ++it)
        delete (*it);
    this->pins.clear();
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        delete (*it);
    this->gates.clear();
}

void nts::Logger::dump(void) const
{
    std::cout << "Logger ->\t\t" << this->name << std::endl;
    this->AComponent::dump();
}

void nts::Logger::openGates()
{
    for (auto it = this->gates.begin(); it != this->gates.end(); ++it)
        (*it)->toggle();
}

