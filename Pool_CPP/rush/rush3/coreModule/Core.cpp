/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** Core.cpp
*/
#include "Core.hpp"
#include "IEngine.hpp"
#include <Clock.hpp>
#include <chrono>

Core::Core(int argc, char const *argv[])
{}

Core::~Core()
{
    isAlive = false;
    for (auto &th : threads) {
        th.join();
    }
}

void Core::startMainloop(int refreshFrequency, std::unique_ptr<IEngine> engine)
{
    threads.emplace_back(isAlive, refreshFrequency, std::move(engine));
}

void Core::threadLoop(bool &isAlive, int refreshFrequency, std::unique_ptr<IEngine> engine);
{
    refreshFrequency = 1000000/refreshFrequency;
    engine->init();

    sf::Clock clock;
    long next = clock.getElapsedTime().asMicroseconds();
    while (isAlive) {
        next += refreshFrequency;
        engine->refresh();
        long actual = clock.getElapsedTime().asMicroseconds();
        if (actual < next)
            std::this_thread::sleep_for(std::clock::microseconds(next - actual));
    }
}
