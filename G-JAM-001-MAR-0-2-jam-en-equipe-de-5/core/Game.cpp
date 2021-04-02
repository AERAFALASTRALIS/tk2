/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Game.cpp
*/
#include "Game.hpp"
#include "engine/Engine.hpp"
#include "engine/GraphicEngine.hpp"
#include "engine/Entity.hpp"
#include "engine/EntityType.hpp"
#include "Spaceship.hpp"
#include "Earth.hpp"
#include "Projectile.hpp"
#include "tools/Save.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <random>

Game *Game::instance = nullptr;

Game::Game(std::shared_ptr<Engine> &engine, std::shared_ptr<GraphicEngine> &gEngine) : engine(engine), gEngine(gEngine), dist(-3.1415926, 3.1415926)
{
    instance = this;
    // create everything, absolutely everything
    earth = std::make_shared<Earth>(512, 512, 16, 0.001);
    playerGroup = std::make_shared<EntityType<Entity>>(18+2);
    earthGroup = std::make_shared<EntityType<Entity>>(128+2);
    projectiles = std::make_shared<EntityType<Entity>>(3);
    asteroids = std::make_shared<EntityType<Entity>>(32);
    noooo = std::make_shared<EntityType<Entity>>(256);
    earthGroup->insert(earth);
    engine->setRelation(projectiles, asteroids, Projectile::hurtYou);
    engine->setRelation(projectiles, earthGroup, Projectile::hurtYou);
    engine->setRelation(asteroids, playerGroup, Projectile::hurtYou);
    engine->setRelation(asteroids, earthGroup, Projectile::hurtYou);
    engine->setRelation(playerGroup, earthGroup, Projectile::hurtYou);
    players.push_back(std::make_shared<Spaceship>(256+128, 256+128, -3.1415926/4, 0, "Spaceship1"));
    players.push_back(std::make_shared<Spaceship>(768-128, 768-128, 3.1415926*3/4, 0, "Spaceship2"));
    soundBuffer.loadFromFile("sounds/shoot.wav");
    hurted.loadFromFile("sounds/crash.wav");
    for (int i = 0; i < 8; ++i) {
        sounds[i].setBuffer(soundBuffer);
        sounds[i].setVolume(50);
    }
    sounds2[0].setBuffer(hurted);
    sounds2[1].setBuffer(hurted);
    sounds2[2].setBuffer(hurted);
    sounds2[3].setBuffer(hurted);
    auto tmp = std::make_shared<Spaceship>(384-22, 512, -3.1415926/2, 0, "Base", 0);
    tmp->shoot = true;
    players.push_back(tmp);
    tmp = std::make_shared<Spaceship>(1024-384+22, 512, 3.1415926/2, 0, "Base", 0);
    tmp->shoot = true;
    players.push_back(tmp);
    tmp = std::make_shared<Spaceship>(512, 384-22, 0, 0, "Base", 0);
    tmp->shoot = true;
    players.push_back(tmp);
    tmp = std::make_shared<Spaceship>(512, 1024-384+22, 3.1415926, 0, "Base", 0);
    tmp->shoot = true;
    players.push_back(tmp);
    for (auto &p : players) {
        playerGroup->insert(p);
    }
}

Game::~Game()
{
    playerGroup.reset();
    earthGroup.reset();
    projectiles.reset();
    asteroids.reset();
    instance = nullptr;
}

void Game::save(Save &sav)
{
    playerGroup->saveAll<Spaceship>(sav, "E-player");
    earthGroup->saveAll<Earth>(sav, "E-earth");
    projectiles->saveAll<Projectile, ProjectileData>(sav, "E-bullets");
    asteroids->saveAll<Projectile, ProjectileData>(sav, "E-asteroids");
}

void Game::load(Save &sav)
{
    playerGroup->loadAll<Spaceship>(sav, "E-player");
    earthGroup->loadAll<Earth>(sav, "E-earth");
    projectiles->loadAll<Projectile, ProjectileData>(sav, "E-bullets");
    asteroids->loadAll<Projectile, ProjectileData>(sav, "E-asteroids");
}

void Game::handleEvent(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Key::Q:players[0]->left = true;break;
                    case sf::Keyboard::Key::D:players[0]->right = true;break;
                    case sf::Keyboard::Key::Z:players[0]->up = true;break;
                    case sf::Keyboard::Key::S:players[0]->damp = true;break;
                    case sf::Keyboard::Key::Space:players[0]->shoot = true;break;
                    case sf::Keyboard::Key::Left:players[1]->left = true;break;
                    case sf::Keyboard::Key::Right:players[1]->right = true;break;
                    case sf::Keyboard::Key::Up:players[1]->up = true;break;
                    case sf::Keyboard::Key::Down:players[1]->damp = true;break;
                    case sf::Keyboard::Key::RControl:players[1]->shoot = true;break;
                    default:;
                }
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Key::Q:players[0]->left = false;break;
                    case sf::Keyboard::Key::D:players[0]->right = false;break;
                    case sf::Keyboard::Key::Z:players[0]->up = false;break;
                    case sf::Keyboard::Key::S:players[0]->damp = false;break;
                    case sf::Keyboard::Key::Space:players[0]->shoot = false;break;
                    case sf::Keyboard::Key::Left:players[1]->left = false;break;
                    case sf::Keyboard::Key::Right:players[1]->right = false;break;
                    case sf::Keyboard::Key::Up:players[1]->up = false;break;
                    case sf::Keyboard::Key::Down:players[1]->damp = false;break;
                    case sf::Keyboard::Key::RControl:players[1]->shoot = false;break;
                    default:;
                }
                break;
            case sf::Event::Closed:
                alive = false;
            default:;
        }
    }
}

void Game::shoot(int x, int y, float angle, float velocity, float damage)
{
    projectiles->insert(std::make_shared<Projectile>(x, y, angle, velocity, damage, "Shoot"));
    sounds[idx++].play();
    idx &= 7;
}

void Game::addAsteroid()
{
    const float angle = dist(rdev);
    const float x = cos(angle) * -768 + 512;
    const float y = sin(angle) * -768 + 512;
    asteroids->insert(std::make_shared<Projectile>(x, y, angle + 3.1415926/2, 0.7, 5.5, "Asteroid"));
    if (getRandom() > 3.)
        noooo->insert(std::make_shared<Entity>("Noon", -512, 512 + 128 * getRandom(), 0, 6, 0, 1, 0, 1));
}

bool Game::isAlive()
{
    return (alive && earth->isAlive());
}

void Game::hurtSound()
{
    sounds2[idx2++].play();
    idx2 &= 3;
}
