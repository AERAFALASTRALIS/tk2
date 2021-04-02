/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicJauge.hpp
*/

#ifndef GRAPHICJAUGE_HPP_
#define GRAPHICJAUGE_HPP_

#include "GraphicElement.hpp"
#include "VertexArray.hpp"

class GraphicJauge : public GraphicElement {
public:
    GraphicJauge();
    virtual ~GraphicJauge();
    GraphicJauge(const GraphicJauge &cpy) = default;
    GraphicJauge &operator=(const GraphicJauge &src) = default;

    // must be included between 0 and 1
    void setValue(float value);
    virtual void onResize() override;
    virtual void update() override;
    virtual void draw() override;
private:
    VertexArray buffer;
};

#endif /* GRAPHICJAUGE_HPP_ */
