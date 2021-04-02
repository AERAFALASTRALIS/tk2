/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Engine.hpp
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "tools/BaseThreadedModule.hpp"
#include "EntityType.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>

class Entity;

// Note : engine must be created AFTER GraphicEngine
class Engine : public BaseThreadedModule {
public:
    Engine();
    virtual ~Engine();
    Engine(const Engine &cpy) = default;
    Engine &operator=(const Engine &src) = default;
    static Engine *instance;

    // Insert a collision test between two groups
    template<class E1, class E2>
    void setRelation(std::shared_ptr<EntityType<E1>> &type1, std::shared_ptr<EntityType<E2>> &type2, void (*func)(E1 &self, E2 &target)) {
        const float radius = type1->getRadius() + type2->getRadius();
        colliders.push_back({type1, type2, radius * radius, reinterpret_cast<void (*)(Entity &, Entity &)>(func)});
    }
    virtual void update() override;
    // Internally used
    void addEntityType(EntityType<Entity> *ent);
    void removeEntityType(EntityType<Entity> *ent);
private:
    std::list<EntityType<Entity> *> entities;
    struct Collider {
        std::shared_ptr<EntityType<Entity>> type1;
        std::shared_ptr<EntityType<Entity>> type2;
        float squaredRadius;
        void (*func)(Entity &self, Entity &target);
    };
    std::vector<Collider> colliders;
    int spawntime = 0;
};

#endif /* ENGINE_HPP_ */
