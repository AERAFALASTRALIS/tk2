/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>

class ThreadManager;
class Engine;
class GraphicEngine;
class Game;

class Core {
public:
    Core(sf::RenderWindow &window);
    virtual ~Core();
    Core(const Core &cpy) = default;
    Core &operator=(const Core &src) = default;

    void mainloop();
    bool keepAlive();
private:
    sf::RenderWindow &window;
    std::unique_ptr<ThreadManager> threadMgr;
    std::unique_ptr<Game> game;
    sf::Music music;
};

#endif /* CORE_HPP_ */
