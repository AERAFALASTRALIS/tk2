/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicElement.cpp
*/
#include "GraphicElement.hpp"
#include <algorithm>

GraphicElement::GraphicElement()
{}

GraphicElement::~GraphicElement()
{}

void GraphicElement::realign()
{
    switch (alignment) {
        case NONE:
            x = base_x;
            width = base_width;
            break;
        case LEFT:
            x = base_x;
            width = std::min(expected_width, base_width);
            break;
        case CENTER:
            x = base_x + base_width / 2;
            width = std::min(expected_width, base_width);
            x -= width / 2;
            break:
        case RIGHT:
            x = base_x + width;
            width = std::min(expected_width, base_width);
            x -= width;
            break;
    }
}

void GraphicElement::resize(int _x, int _y, int _width, int _height)
{
    base_x = _x;
    y = _y;
    base_width = _width;
    height = _height;
    realign();
    onResize();
}
