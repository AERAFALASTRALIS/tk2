/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicElement.hpp
*/

#ifndef GRAPHICELEMENT_HPP_
#define GRAPHICELEMENT_HPP_

#include <memory>
#include "IMonitorGraphic.hpp"

class GraphicElement : public IMonitorGraphic {
public:
    enum align {
        NONE,
        LEFT,
        CENTER,
        RIGHT
    };
    GraphicElement();
    virtual ~GraphicElement();
    GraphicElement(const GraphicElement &cpy) = default;
    GraphicElement &operator=(const GraphicElement &src) = default;

    virtual void setTarget(sf::RenderWindow *_target) override {target = _target;}
    virtual void setContent(std::shared_ptr<IMonitorModule> _content) override {content = _content;}
    virtual void onResize() = 0;
    void realign();
    virtual void resize(int _x, int _y, int _width, int _height) override;
    // virtual void update() = 0;
    // virtual void draw() = 0;
protected:
    int base_x = 0;
    int base_width = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int expected_width = 0;
    sf::RenderWindow *target;
    std::shared_ptr<IMonitorModule> content;
    enum align alignment = NONE;
};

#endif /* GRAPHICELEMENT_HPP_ */
