/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicGraph.hpp
*/

#ifndef GRAPHICGRAPH_HPP_
#define GRAPHICGRAPH_HPP_

#include "GraphicElement.hpp"
#include <deque>
#include <VertexArray.hpp>
#include <Color.hpp>

class GraphicGraph : public GraphicElement {
public:
    GraphicGraph();
    virtual ~GraphicGraph();
    GraphicGraph(const GraphicGraph &cpy) = default;
    GraphicGraph &operator=(const GraphicGraph &src) = default;

    void setColor(const sf::Color &color);
    void pushValue(float value);
    virtual void onResize() override;
    virtual void update() override;
    virtual void draw() override;
private:
    sf::Color color = sf::Color::Green;
    int size = 0;
    std::deque<float> values;
    VertexArray buffer;
};

#endif /* GRAPHICGRAPH_HPP_ */
