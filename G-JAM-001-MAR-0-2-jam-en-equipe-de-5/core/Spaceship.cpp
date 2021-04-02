/*
** EPITECH PROJECT, 2021
** gamejam2
** File description:
** Spaceship
*/

#include "Spaceship.hpp"
#include "Game.hpp"

Spaceship::Spaceship(int x, int y, float angle, float velocity, const std::string &name, float shield) : Entity(name, x, y, angle, 0, 0, shield, 0.002)
{
    accelerate(velocity);
    deduceTurret = (shield == 0);
}

void Spaceship::update()
{
    if (shootDelay-- <= 0 && shoot) {
        Game::instance->shoot(refX, refY, getRotation() + deduceTurret * Game::instance->getRandom() / 6, 4, 6);
        shootDelay = 30;
    }
    if (up)
        accelerate(0.05);
    dampening(damp ? 0.1 : 0.01);
    if (left)
        rotate(-0.06);
    if (right)
        rotate(0.06);
}

std::shared_ptr<Spaceship> Spaceship::load(EntityData &sav)
{
    auto tmp = std::shared_ptr<Spaceship>(new Spaceship());

    tmp->loadMe(sav);
    return tmp;
}

void Spaceship::loadMe(EntityData &sav)
{
    Entity::load(sav);
}

EntityData Spaceship::save()
{
    return Entity::save();
}

Spaceship::~Spaceship() {

}
