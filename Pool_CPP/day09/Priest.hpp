/*
** EPITECH PROJECT, 2021
** priest
** File description:
** priest
*/

#ifndef PRIEST_H_
#define PRIEST_H_

#include "Mage.hpp"

class Priest : public Mage
{
public:
    Priest(const std::string &name, int level);
    ~Priest();
    int CloseAttack();
    void Heal();
};

#endif
