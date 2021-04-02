/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Engine.cpp
*/
#include "Engine.hpp"
#include "GraphicEngine.hpp"
#include "EntityType.hpp"
#include "Entity.hpp"
#include "core/Game.hpp"

Engine *Engine::instance = nullptr;

Engine::Engine() : BaseThreadedModule(GraphicEngine::instance->paused)
{
    instance = this;
}

Engine::~Engine()
{
    instance = nullptr;
}

void Engine::update()
{
    for (auto &v : colliders) {
        v.type1->collideAll(v.type2, v.squaredRadius, v.func);
    }
    for (auto v : entities) {
        v->updateAll();
    }
    if (++spawntime >= 40) {
        Game::instance->addAsteroid();
        spawntime = 0;
    }
    if (!Game::instance->isAlive()) {
        colliders.clear();
        ready = false;
    }
}

void Engine::addEntityType(EntityType<Entity> *ent)
{
    entities.push_back(ent);
}

void Engine::removeEntityType(EntityType<Entity> *ent)
{
    entities.remove(ent);
}
