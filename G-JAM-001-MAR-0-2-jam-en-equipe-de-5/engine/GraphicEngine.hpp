/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** GraphicEngine.hpp
*/

#ifndef GRAPHICENGINE_HPP_
#define GRAPHICENGINE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "tools/BaseThreadedModule.hpp"
#include "EntityType.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class GraphicEngine : public BaseThreadedModule {
public:
    GraphicEngine(sf::RenderWindow &window);
    virtual ~GraphicEngine();
    GraphicEngine(const GraphicEngine &cpy) = default;
    GraphicEngine &operator=(const GraphicEngine &src) = default;

    static GraphicEngine *instance;

    virtual void refresh() override;
    virtual void update() override;
    virtual void postUpdate() override;
    virtual void onPausePost() override;
    virtual void init() override;
    // Internally used
    void addEntityType(EntityType<Entity> *ent);
    void removeEntityType(EntityType<Entity> *ent);
private:
    bool isPaused = false;
    sf::RenderWindow &window;
    std::list<EntityType<Entity> *> entities;
    const sf::View view;
};

#endif /* GRAPHICENGINE_HPP_ */
