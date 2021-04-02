/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** Core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>
class IEngine;

class Core {
public:
    Core(int argc, char const *argv[]);
    virtual ~Core();
    Core(const Core &cpy) = delete;
    Core &operator=(const Core &src) = delete;

    void startMainloop(int refreshFrequency, std::unique_ptr<IEngine> engine);
private:
    bool isAlive = true;
    static void threadLoop(bool &isAlive, int refreshFrequency, std::unique_ptr<IEngine> engine);
    std::vector<std::thread> threads;
};

#endif /* CORE_HPP_ */
