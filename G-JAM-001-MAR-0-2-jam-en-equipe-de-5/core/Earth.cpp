/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Earth.cpp
*/
#include "Earth.hpp"

Earth::Earth(int x, int y, float shield, float shieldRecover) : Entity("Earth", x, y, 0, 0, 0, shield, shieldRecover, 24)
{}

Earth::~Earth()
{}

std::shared_ptr<Earth> Earth::load(EntityData &sav)
{
    auto tmp = std::shared_ptr<Earth>(new Earth());

    tmp->loadme(sav);
    return tmp;
}

void Earth::loadme(EntityData &sav)
{
    Entity::load(sav);
}

EntityData Earth::save()
{
    return Entity::save();
}
