/*
** EPITECH PROJECT, 2021
** mage
** File description:
** mage
*/

#ifndef MAGE_H_
#define MAGE_H_

#include "Character.hpp"

class Mage : virtual public Character
{
public:
    Mage(const std::string &name, int level);
    ~Mage();
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
};

#endif
