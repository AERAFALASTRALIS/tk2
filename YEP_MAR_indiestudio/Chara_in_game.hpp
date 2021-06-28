/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef CHARA_IN_GAME_HPP_
#define CHARA_IN_GAME_HPP_

#include "Assets3DHandler.hpp"
#include "irrlicht.h"
#include "Parametre.hpp"

class Chara_in_game {
    public:
        Chara_in_game(int id, Player_config player_config, irr::core::vector3df pos);
        ~Chara_in_game();
        void move_player(direction what_you_want_to_go);
        void set_anim(anim new_anim);
        std::map<key_for_player, std::string> get_map_key();
        irr::core::vector3d<float> get_pos();
        irr::core::vector3d<float> get_old_pos();
        void set_pos(irr::core::vector3d<float> new_pos);
        void set_old_pos(irr::core::vector3d<float> new_pos);

    protected:
        int _id;
        std::map<key_for_player, std::string> _map_key;
        Graphical::typeObj _type_object;
        anim _animation;
        irr::core::vector3d<float> _pos;
        irr::core::vector3d<float> _old_pos;
        direction _direction;
        bool _ia;
    private:
};

#endif /* !CHARA_IN_GAME_HPP_ */
