/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicText.hpp
*/

#ifndef GRAPHICTEXT_HPP_
#define GRAPHICTEXT_HPP_

#include "GraphicElement.hpp"

namespace sf {
    class Font;
    class Color;
};

class GraphicText : public GraphicElement {
public:
    GraphicText();
    virtual ~GraphicText();
    GraphicText(const GraphicText &cpy) = default;
    GraphicText &operator=(const GraphicText &src) = default;

    void setText(const std::string &text);
    void setFillColor(const Color &color);
    void setCharacterSize(unsigned int size);
    void setAlignment(enum align _alignment) {alignment = _alignment;}
    virtual void onResize() override;
    virtual void update() override;
    virtual void draw() override;
    static void setFont(std::unique_ptr<Font> font);
private:
    bool hasChanged = false;
    std::string text;
    std::unique_ptr<sf::Text> out;
    static std::unique_ptr<Font> font;
};

#endif /* GRAPHICTEXT_HPP_ */
