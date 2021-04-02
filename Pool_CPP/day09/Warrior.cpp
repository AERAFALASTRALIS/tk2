/*
** EPITECH PROJECT, 2021
** warior
** File description:
** warior
*/

#include <iostream>
#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strenght = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    this->Range = Character::CLOSE;
    this->weaponName = std::string ("hammer");
    std::cout << "I'm " << this->_name << "  KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{

}

int Warrior::CloseAttack()
{
    int dmg = 0;
    if (this->_power >= 30)
    {
        this->_power -= 30;
        dmg = 20 + this->_strenght;
        std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

int Warrior::RangeAttack()
{
    int dmg = 0;
    if (this->_power >= 10)
    {
        this->_power -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    this->Range = CLOSE;
    return (dmg);
}
