/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** GraphicEngine.cpp
*/
#include "GraphicEngine.hpp"
#include "core/Game.hpp"

GraphicEngine *GraphicEngine::instance = nullptr;

GraphicEngine::GraphicEngine(sf::RenderWindow &window) : BaseThreadedModule(isPaused), window(window), view({0, 0, 1024, 1024})
{
    instance = this;
    window.setSize({1024, 1024});
    window.setView(view);
}

void GraphicEngine::init()
{
    ready = true;
}

GraphicEngine::~GraphicEngine()
{
    instance = nullptr;
}

void GraphicEngine::refresh()
{
    window.setView(view);
    window.clear(); // Replace by a background draw
    for (auto &e : entities) {
        e->drawAll();
    }
}

void GraphicEngine::update()
{
    Game::instance->handleEvent(window);
    ready = Game::instance->isAlive();
}

void GraphicEngine::postUpdate()
{
    window.display();
}

void GraphicEngine::onPausePost()
{
    // Querry events here (pause mode)
    window.display();
}

void GraphicEngine::addEntityType(EntityType<Entity> *ent)
{
    entities.push_back(ent);
}

void GraphicEngine::removeEntityType(EntityType<Entity> *ent)
{
    entities.remove(ent);
}
