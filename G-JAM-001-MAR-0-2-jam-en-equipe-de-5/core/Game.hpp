/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Game.hpp
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>
#include <memory>
#include <vector>
#include <random>
#include "engine/EntityType.hpp"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Engine;
class GraphicEngine;
class Entity;
class Spaceship;
class Earth;
class Save;

// Handle for game resources
class Game {
public:
    Game(std::shared_ptr<Engine> &engine, std::shared_ptr<GraphicEngine> &gEngine);
    virtual ~Game();
    Game(const Game &cpy) = delete;
    Game &operator=(const Game &src) = delete;
    static Game *instance;

    void save(Save &sav);
    void load(Save &sav);
    void handleEvent(sf::RenderWindow &window);
    void shoot(int x, int y, float angle, float velocity, float damage);
    void addAsteroid();
    bool isAlive();
    float getRandom() {return dist(rdev);}
    void hurtSound();
private:
    std::shared_ptr<Engine> engine;
    std::shared_ptr<GraphicEngine> gEngine;
    std::vector<std::shared_ptr<Spaceship>> players;
    std::shared_ptr<Earth> earth;
    std::shared_ptr<EntityType<Entity>> playerGroup;
    std::shared_ptr<EntityType<Entity>> earthGroup;
    std::shared_ptr<EntityType<Entity>> projectiles;
    std::shared_ptr<EntityType<Entity>> asteroids;
    std::shared_ptr<EntityType<Entity>> towers;
    std::shared_ptr<EntityType<Entity>> noooo;
    std::random_device rdev;
    std::uniform_real_distribution<float> dist;
    bool alive = true;
    int idx = 0;
    int idx2 = 0;
    sf::SoundBuffer soundBuffer;
    sf::SoundBuffer hurted;
    sf::Sound sounds[8];
    sf::Sound sounds2[4];
};

#endif /* GAME_HPP_ */
