/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** GraphicCanvas.hpp
*/

#ifndef GRAPHICCANVAS_HPP_
#define GRAPHICCANVAS_HPP_

#include "IMonitorGraphic.hpp"
#include <memory>
#include <vector>

namespace sf {
    class Sprite;
    class Texture;
};

class GraphicCanvas : public IMonitorGraphic {
public:
    struct Content {
        std::unique_ptr<IMonitorGraphic> monitor;
        int margin_left;
        int margin_right;
        int margin_top;
        int margin_bottom;
        int max_width;
        int max_height;
        int min_width;
        int min_height;
    };

    GraphicCanvas();
    virtual ~GraphicCanvas();
    GraphicCanvas(const GraphicCanvas &cpy) = default;
    GraphicCanvas &operator=(const GraphicCanvas &src) = default;

    void setTexture(std::shared_ptr<Texture> tex);
    void push(std::unique_ptr<IMonitorGraphic> content, int margin_left, int margin_right, int margin_top, int margin_bottom, int max_width, int max_height, int min_width, int min_height);
    virtual void setTarget(sf::RenderWindow *_target) override {target = _target;}
    virtual void setContent(std::shared_ptr<IMonitorModule> content) override {}
    virtual void resize(int x, int y, int width, int height) override;
    virtual void update() override;
    virtual void draw() override;
private:
    static void resize(Content &content);
    int x = 0;
    int y = 0;
    int width = 800;
    int height = 600;
    std::vector<Content> list;
    std::unique_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> texture;
    sf::RenderWindow *target = nullptr;
};

#endif /* GRAPHICCANVAS_HPP_ */
