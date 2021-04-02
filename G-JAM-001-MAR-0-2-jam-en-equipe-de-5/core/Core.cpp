/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Core.cpp
*/
#include "Core.hpp"
#include "engine/Engine.hpp"
#include "engine/GraphicEngine.hpp"
#include "tools/ThreadManager.hpp"
#include "engine/Entity.hpp"
#include "engine/EntityType.hpp"
#include "Game.hpp"

Core::Core(sf::RenderWindow &window) : window(window)
{
    threadMgr = std::make_unique<ThreadManager>();
    Entity::bindWindow(window);
    Entity::loadTexture("ast_medium.png", "Asteroid");
    Entity::loadTexture("bullet.png", "Shoot");
    Entity::loadTexture("earth.png", "Earth");
    Entity::loadTexture("spaceship01.png", "Spaceship1");
    Entity::loadTexture("spaceship06.png", "Spaceship2");
    Entity::loadTexture("vehicule.png", "Base");
    Entity::loadTexture("non.png", "Noon");
    music.openFromFile("musique/p1.ogg");
    music.setLoop(true);
}

Core::~Core()
{
    Entity::unloadTextures();
}

void Core::mainloop()
{
    if (!window.isOpen())
        return;
    auto gEngine = std::make_shared<GraphicEngine>(window);
    auto engine = std::make_shared<Engine>();

    game = std::make_unique<Game>(engine, gEngine);
    threadMgr->startMainloop(60, gEngine);
    threadMgr->startMainloop(60, engine);
    music.play();
    threadMgr->mainloop();
    music.stop();
    game.reset();
}

bool Core::keepAlive()
{
    return window.isOpen();
}
