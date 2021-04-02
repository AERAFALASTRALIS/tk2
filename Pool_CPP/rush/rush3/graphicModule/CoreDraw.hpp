/*
** EPITECH PROJECT, 2020
** B-CPP-300-MAR-3-1-CPPrush3-antoine.viala
** File description:
** CoreDraw.hpp
*/

#ifndef COREDRAW_HPP_
#define COREDRAW_HPP_

#include "IEngine.hpp"
#include <RenderWindow.hpp>
#include <memory>
class IMonitorGraphic;

class CoreDraw : public IEngine {
public:
    CoreDraw(bool fullscreen, const std::string &name = "nameless", int width = 800, int height = 600);
    virtual ~CoreDraw();
    CoreDraw(const CoreDraw &cpy) = default;
    CoreDraw &operator=(const CoreDraw &src) = default;
    virtual void init() override;
    virtual void refresh() override;
    virtual bool isReady() const override {return true;}
    void push(std::unique_ptr<IMonitorGraphic> c);
    sf::RenderWindow *getWindow() const {return &window;}
private:
    sf::RenderWindow window;
    bool fullscreen;
    std::string name;
    int width;
    int height;
    std::vector<std::unique_ptr<IMonitorGraphic>> content;
};

#endif /* COREDRAW_HPP_ */
