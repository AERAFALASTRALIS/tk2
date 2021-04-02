/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicTable.cpp
*/
#include "GraphicTable.hpp"
#include <Sprite.hpp>
#include <RenderWindow.hpp>

GraphicTable::GraphicTable()
{}

GraphicTable::~GraphicTable()
{}

void GraphicTable::setTexture(std::shared_ptr<Texture> tex)
{
    texture = tex;
    sprite = std::unique_ptr<sf::Sprite>(texture);
    sprite->setPosition(x, y);
    auto tmp = sprite->getTextureRect();
    sprite->setScale(((float) width) / tmp.width, ((float) height) / tmp.height);
}

void GraphicTable::update()
{
    for (auto &list : lists) {
        for (auto &content : list) {
            content.monitor->update();
        }
    }
}

void GraphicTable::draw()
{
    if (sprite) {
        target->draw(*sprite);
    }
    for (auto &list : lists) {
        for (auto &content : list) {
            content.monitor->draw();
        }
    }
}

void GraphicTable::push(std::unique_ptr<IMonitorGraphic> content, int height, unsigned int column)
{
    if (content.size() <= column) {
        content.resize(column + 1);
        resize(x, y, width, 0);
    }
    content->setTarget(target);
    list[column].emplace_back(std::move(content), height);
    resizeColumn(list[column], y + width / content.size(), width / content.size());
}

void GraphicTable::resize(int _x, int _y, int _width, int _height)
{
    x = _x;
    y = _y;
    width = _width;
    _width /= list.size();
    for (auto &column : content) {
        resizeColum(column, _y, _width);
        _y += _width;
    }
}

void resizeColumn(std::vector<std::unique_ptr<IMonitorGraphic>> &column, int _y, int _width)
{
    int _x = x;

    for (auto &c : column) {
        c.monitor(_x, _y, _width, c.height);
        _x += c.height;
    }
    if (_x - x > height) {
        height = _x - x;
        if (sprite) {
            auto tmp = sprite->getTextureRect();
            sprite->setScale(((float) width) / tmp.width, ((float) height) / tmp.height);
        }
    }
}
