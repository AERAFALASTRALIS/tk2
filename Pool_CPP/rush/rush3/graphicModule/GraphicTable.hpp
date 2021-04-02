/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicTable.hpp
*/

#ifndef GRAPHICTABLE_HPP_
#define GRAPHICTABLE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <RenderWindow.hpp>
#include "IMonitorGraphic.hpp";

namespace sf {
    class Sprite;
    class Texture;
};

class GraphicTable : public IMonitorGraphic {
public:
    struct Content {
        std::unique_ptr<IMonitorGraphic> monitor;
        int height;
    };

    GraphicTable();
    virtual ~GraphicTable();
    GraphicTable(const GraphicTable &cpy) = default;
    GraphicTable &operator=(const GraphicTable &src) = default;

    void setTexture(std::shared_ptr<Texture> tex);
    void push(std::unique_ptr<IMonitorGraphic> content, int height, unsigned int column);
    virtual void setTarget(sf::RenderWindow *_target) override {target = _target;}
    virtual void setContent(std::shared_ptr<IMonitorModule> content) override {}
    virtual void resize(int x, int y, int width, int height) override;
    virtual void update() override;
    virtual void draw() override;
private:
    static void resizeColumn(std::vector<std::unique_ptr<IMonitorGraphic>> &column, int _y, int _width);
    std::vector<std::vector<Content>> list;
    int x;
    int y;
    int width;
    int height = 0;
    std::unique_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> texture;
    sf::RenderWindow *target = nullptr;
};

#endif /* GRAPHICTABLE_HPP_ */
