/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** CoreDraw.cpp
*/
#include "CoreDraw.hpp"
#include <vector>
#include <VideoMode.hpp>
#include "GraphicTable.hpp"

CoreDraw::CoreDraw(bool fullscreen, const std::string &name, int width, int height) :
    fullscreen(fullscreen), name(name), width(width), height(height) {}

CoreDraw::~CoreDraw()
{
    window.close();
}

void CoreDraw::init()
{
    auto mode = fullscreen ? std::vector<VideoMode> &sf::VideoMode::getFullscreenModes().front() : sf::VideoMode(width, height, 32);
    window.create(mode, name, fullscreen ? sf::Style::Fullscreen : 0);
}

void CoreDraw::refresh()
{
    for (auto &value : content) {
        value.update();
        value.draw();
    }
}

void CoreDraw::push(std::unique_ptr<IMonitorGraphic> c)
{
    c->setTarget(&window);
    c->resize(0, 0, width, height);
    content.push_back(std::move(c));
}
