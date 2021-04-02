/*
** EPITECH PROJECT, 2021
** priest
** File description:
** priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_name = name;
    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->_strenght = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    this->Range = Character::CLOSE;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{

}

int Priest::CloseAttack()
{
    int dmg = 0;
    if (this->_power >= 10)
    {
        this->_power -= 10;
        dmg = 10 + this->_spirit;
        std::cout << this->_name << " uses a spirit explosion" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
    return (dmg);
}

void Priest::Heal()
{
    if (this->_power >= 10)
    {
        this->_power -= 10;
        this->_pv += 70;
        if (this->_pv > 100)
            this->_pv = 100;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
}
