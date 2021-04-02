/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Projectile.hpp
*/

#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#include <string>
#include <memory>
#include "engine/Entity.hpp"

struct ProjectileData {
    EntityData base;
};

class Projectile : public Entity {
public:
    Projectile(int x, int y, float angle, float velocity, float damage, const std::string &name = "Asteroid");
    virtual ~Projectile();
    static std::shared_ptr<Projectile> load(ProjectileData &sav);
    ProjectileData save();
    static void hurtYou(Entity &self, Entity &you);
    virtual void update() override;
private:
    void loadme(ProjectileData &sav);
    Projectile() = default;
    int lifetime = 1000;
};

#endif /* PROJECTILE_HPP_ */
