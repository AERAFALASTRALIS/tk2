/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** IMonitorDisplay.hpp
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorModule;
#include <memory>

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay() {}
    virtual void setContent(std::shared_ptr<IMonitorModule> content) = 0;
    virtual void resize(int x, int y, int width, int height) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif /* IMONITORDISPLAY_HPP_ */
