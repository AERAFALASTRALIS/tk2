/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicJauge.cpp
*/
#include "GraphicJauge.hpp"
#include <RenderWindow.hpp>
#include <Color.hpp>

GraphicJauge::GraphicJauge() : buffer(sf::PrimitiveType::TriangleStrip, 8);
{
    buffer[0].color = sf::Color::RED;
    buffer[1].color = sf::Color::RED;
    buffer[2].color = sf::Color::GREEN;
    buffer[3].color = sf::Color::GREEN;
    buffer[4].color = sf::Color::BLACK;
    buffer[5].color = sf::Color::BLACK;
    buffer[6].color = sf::Color::BLACK;
    buffer[7].color = sf::Color::BLACK;
}

GraphicJauge::~GraphicJauge()
{}

void GraphicJauge::setValue(float value)
{
    float _x = x + (1.f - value) * width;
    buffer[6].position.x = _x;
    buffer[7].position.x = _x;
}

void GraphicJauge::onResize()
{
    buffer[0].position.x = x;
    buffer[1].position.x = x;
    buffer[6].position.x = x;
    buffer[7].position.x = x;
    buffer[2].position.x = x + width;
    buffer[3].position.x = x + width;
    buffer[4].position.x = x + width;
    buffer[5].position.x = x + width;
    buffer[0].position.y = y;
    buffer[2].position.y = y;
    buffer[4].position.y = y;
    buffer[6].position.y = y;
    buffer[1].position.y = y + height;
    buffer[3].position.y = y + height;
    buffer[5].position.y = y + height;
    buffer[7].position.y = y + height;
}

void GraphicJauge::update()
{
    setValue(content->getValue());
}

void GraphicJauge::draw()
{
    target->draw(content);
}
