/*
** EPITECH PROJECT, 2021
** fede
** File description:
** fede
*/

#include <iostream>
#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_widht = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    std::cout << "The ship USS " << this->_name << " has been finished.\nIt is " << this->_length << " m in length and " << this->_widht << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship(void)
{

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::string tmp = "unstable";

    if (this->_core->checkReactor()->isStable() == true)
        tmp = "stable";
    std::cout << "USS " << this->_name << ": The core is " << tmp << " at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_widht = width;
    this->_name = name;
    this->_maxWarp = 1;
    std::cout << "The independent ship " << this->_name << " just finished its construction.\nIt is " << this->_length << " m in length and " << this->_widht << " m in width." << std::endl;
}

Federation::Ship::~Ship(void)
{

}

void Federation::Ship::setupCore(WarpSystem::Core*core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    std::string tmp = "unstable";

    if (this->_core->checkReactor()->isStable() == true)
        tmp = "stable";
    std::cout << this->_name << ": The core is " << tmp << " at the time." << std::endl;
}
