/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Projectile.cpp
*/
#include "Projectile.hpp"
#include "Game.hpp"

Projectile::Projectile(int x, int y, float angle, float velocity, float damage, const std::string &name) : Entity(name, x, y, angle, 0, 0, damage, 0, 1)
{
    accelerate(velocity);
}

Projectile::~Projectile()
{}

std::shared_ptr<Projectile> Projectile::load(ProjectileData &sav)
{
    auto tmp = std::shared_ptr<Projectile>(new Projectile());

    tmp->loadme(sav);
    return tmp;
}

void Projectile::loadme(ProjectileData &sav)
{
    Entity::load(sav.base);
}

ProjectileData Projectile::save()
{
    return {Entity::save()};
}

void Projectile::hurtYou(Entity &self, Entity &you)
{
    you.damageShield(self.getShieldPower(), self);
    self.kill();
    Game::instance->hurtSound();
}

void Projectile::update()
{
    if (--lifetime < 0)
        kill();
}
