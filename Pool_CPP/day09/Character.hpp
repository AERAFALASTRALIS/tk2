/*
** EPITECH PROJECT, 2021
** character
** File description:
** character
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>

class Character
{
public:
    Character(const std::string &name, int level);
    ~Character();
    const std::string &getName() const;
    int getLvl() const;
    int getPv() const;
    int getPower() const;

    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
    void TakeDamage(int _damage);
    enum AttackRange
    {
        CLOSE,
        RANGE
    };
    AttackRange Range;
private:
    std::string _name;
    int _level;
    int _pv;
    int _power;
    int _strenght;
    int _stamina;
    int _intelligence;
    int _spirit;
    int _agility;
};

#endif /*CHARACTER_H_*/
