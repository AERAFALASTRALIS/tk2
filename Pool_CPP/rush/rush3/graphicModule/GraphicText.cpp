/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicText.cpp
*/
#include "GraphicText.hpp"
#include <RenderWindow.hpp>
#include <Font.hpp>
#include <Text.hpp>

std::unique_ptr<Font> font = nullptr;

GraphicText::GraphicText()
{
    out = std::make_unique<Text>();
    out.setFont(font.get());
}

GraphicText::~GraphicText()
{}

void GraphicText::onResize()
{
    hasChanged = true;
}

void GraphicText::setFont(Font *_font)
{
    font = std::unique_ptr<Font>(_font);
}

void GraphicText::setText(const std::string &_text)
{
    if (text != _text) {
        hasChanged = true;
        text = _text;
        out->setString(text);
    }
}

void GraphicText::setFillColor(const Color &color)
{
    out->setFillColor(color);
}

void GraphicText::setCharacterSize(unsigned int size)
{
    out->setCharacterSize(size);
    hasChanged = true;
}

void GraphicText::update()
{
    setText(content->getString());
    if (hasChanged) {
        float tmp = height / text->getLocalBounds().height;
        text->setScale(tmp, tmp);
        expected_width = text->getGlobalBounds().width;
        realign();
        text->setPosition(x, y);
        if (width < expected_width) {
            tmp = (tmp * width) / expected_width;
            text->setScale(tmp, tmp);
        }
        hasChanged = false;
    }
}

void GraphicText::draw()
{
    target->draw(*out);
}
