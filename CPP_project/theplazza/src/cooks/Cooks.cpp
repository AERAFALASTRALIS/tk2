/*
** EPITECH PROJECT, 2021
** cooks
** File description:
** cooks
*/

#include "my.h"
#include "Cooks.hpp"
#include "Log.hpp"

using Plazza::Cooks;

Cooks::Cooks(Pizza *pizza) : _pizza(pizza)
{
}

Cooks::~Cooks()
{
}

void Cooks::cook(std::string &name)
{
    usleep(_pizza->getCookingTime() * 1000000);
    std::cout << "Cook[" << name << "]: " << _pizza->getName() << " " << _pizza->getSize() << " is ready!" << std::endl;
    Log log;
    log.write("Cook[" + name + "]: has done " + _pizza->getName() + " " + _pizza->getSize());
}
