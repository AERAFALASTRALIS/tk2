/*
** EPITECH PROJECT, 2021
** mage
** File description:
** mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strenght = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    this->Range = Character::CLOSE;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage()
{

}

int Mage::CloseAttack()
{
    int dmg = 0;
    if (this->_power >= 10)
    {
        this->_power -= 10;
        std::cout << thi->_name << " blinks" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    this->Range = RANGE;
    return (dmg);
}

int Mage::RangeAttack()
{
    int dmg = 0;
    if (this->power >= 25)
    {
        this->_power -= 25;
        dmg = 20 + this->_spirit;
        std::cout << this->_name << " launches a fire ball" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

void Mage::RestorePower()
{
    this->_power += 50 + this->_intelligence;
    if (this->_power >= 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}
