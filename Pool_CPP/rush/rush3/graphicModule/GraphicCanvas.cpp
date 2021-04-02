/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicCanvas.cpp
*/
#include "GraphicCanvas.hpp"
#include <algorithm>
#include <Sprite.hpp>
#include <RenderWindow.hpp>

GraphicCanvas::GraphicCanvas()
{}

GraphicCanvas::~GraphicCanvas()
{}

void GraphicCanvas::setTexture(std::shared_ptr<Texture> tex)
{
    texture = tex;
    sprite = std::unique_ptr<sf::Sprite>(texture);
    sprite->setPosition(x, y);
    auto tmp = sprite->getTextureRect();
    sprite->setScale(((float) width) / tmp.width, ((float) height) / tmp.height);
}

void GraphicCanvas::resize(Content &content)
{
    int _x = content.margin_left;
    int _y = content.margin_top;
    int _width = std::min(width - content.margin_left - content.margin_right, content.max_width);
    int _height = std::min(height - content.margin_top - content.margin_bottom, content.max_height);

    if (_width < content.min_width) {
        if (width <= content.min_width) {
            _width = width;
            _x = 0;
        } else {
            _x *= ((float) _width) / content.min_width;
            _width = content.min_width;
        }
    }
    if (_height < content.min_height) {
        if (height <= content.min_height) {
            _height = height;
            _y = 0;
        } else {
            _x *= ((float) _height) / content.min_height;
            _height = content.min_height;
        }
    }
    content.monitor->resize(x + _x, y + _y, _width, _height);
}

void GraphicCanvas::push(std::unique_ptr<IMonitorGraphic> content, int margin_left, int margin_right, int margin_top, int margin_bottom, int max_width, int max_height, int min_width, int min_height)
{
    content->setTarget(target);
    list.emplace_back(std::move(content), margin_left, margin_right,
        margin_top, margin_bottom, max_width, max_height, min_width, min_height);
    resize(list.back());
}

void GraphicCanvas::resize(int _x, int _y, int _width, int _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    if (sprite) {
        sprite->setPosition(x, y);
        auto tmp = sprite->getTextureRect();
        sprite->setScale(((float) width) / tmp.width, ((float) height) / tmp.height);
    }
    for (auto &content : list) {
        resize(content);
    }
}

void GraphicCanvas::update()
{
    for (auto &content : list) {
        content.monitor->update();
    }
}

void GraphicCanvas::draw()
{
    if (sprite) {
        target->draw(*sprite);
    }
    for (auto &content : list) {
        content.monitor->draw();
    }
}
