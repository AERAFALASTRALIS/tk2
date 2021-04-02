/*
** EPITECH PROJECT, 2021
** gamejam2
** File description:
** Spaceship
*/

#ifndef SPACESHIP_HPP_
#define SPACESHIP_HPP_

#include <string>
#include <memory>

#include "./../engine/Entity.hpp"

class Spaceship : public Entity {

    enum MoveType {

        RIGHT,
        LEFT,
        UP,
        DAMP,
    };

    public:
        Spaceship(int x, int y, float angle, float velocity, const std::string &name, float shield = 10);
        virtual ~Spaceship();
        virtual void update() override;
        static std::shared_ptr<Spaceship> load(EntityData &sav);
        EntityData save();
        bool up = false;
        bool left = false;
        bool right = false;
        bool damp = false;
        bool shoot = false;
    private:
        bool deduceTurret = false;
        int shootDelay = 0;
        void loadMe(EntityData &sav);
        Spaceship() = default;

        MoveType _action;

};

#endif /* !SPACESHIP_HPP_ */
