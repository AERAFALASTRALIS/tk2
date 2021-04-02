/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicGraph.cpp
*/
#include "GraphicGraph.hpp"
#include <RenderWindow.hpp>
#include <Vector2.hpp>

GraphicGraph::GraphicGraph() : buffer(sf::PrimitiveType::Lines) {}

GraphicGraph::~GraphicGraph() {}

void GraphicGraph::setColor(const sf::Color &_color)
{
    color = _color;
    for (int i = 0; i < size * 2; ++i) {
        buffer[i].color = color;
    }
}

void GraphicGraph::pushValue(float value)
{
    values.pop_back();
    values.push_front(1.f - value);
}

void GraphicGraph::onResize()
{
    if (size != width) {
        buffer.resize(width);
        while (width > size) {
            buffer[size * 2].color = color;
            buffer[(size++ * 2) | 1].color = color;
        }
        size = width;
    }
    values.resize(width);
    for (int i = 0; i < size; ++i) {
        buffer[i * 2].position.x = x + i;
        buffer[(i * 2) | 1].position.x = x + i;
        buffer[(i * 2) | 1].position.y = y + height;
    }
}

void GraphicGraph::update()
{
    pushValue(content->getValue());
    for (int i = 0; i < size; ++i) {
        buffer[i * 2].position.y = y + values[i] * height;
    }
}

void GraphicGraph::draw()
{
    target->draw(content);
}
