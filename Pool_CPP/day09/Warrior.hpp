/*
** EPITECH PROJECT, 2021
** warior
** File description:
** warior
*/

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <iostream>
#include "Character.hpp"

class Warrior : public Character
{
public:
    Warrior(const std::string &name, int level);
    ~Warrior();
    int CloseAttack();
    int RangeAttack();
private:
    std::string weaponName;
};

#endif
