/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Earth.hpp
*/

#ifndef EARTH_HPP_
#define EARTH_HPP_

#include <string>
#include <memory>
#include "engine/Entity.hpp"

class Earth : public Entity {
public:
    Earth(int x, int y, float shield, float shieldRecover);
    virtual ~Earth();
    Earth(const Earth &cpy) = default;
    Earth &operator=(const Earth &src) = default;
    static std::shared_ptr<Earth> load(EntityData &sav);
    EntityData save();
private:
    void loadme(EntityData &sav);
    Earth() = default;
};

#endif /* EARTH_HPP_ */
