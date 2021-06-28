/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Chara_in_game.hpp"

Chara_in_game::Chara_in_game(int id, Player_config player_config, irr::core::vector3df pos)
{
    this->_id = id;
    this->_map_key = player_config.key;
    this->_type_object = player_config.model_chara;
    this->_ia = player_config.robot;
    this->_pos = pos;
    this->_old_pos = pos;
    this->_animation = anim::AFK;
}

Chara_in_game::~Chara_in_game()
{
}

std::map<key_for_player, std::string> Chara_in_game::get_map_key()
{
    return (this->_map_key);
}

void Chara_in_game::set_anim(anim new_anim)
{
    this->_animation = new_anim;
}

void Chara_in_game::set_pos(irr::core::vector3d<float> new_pos)
{
    this->_pos = new_pos;
}

void Chara_in_game::set_old_pos(irr::core::vector3d<float> new_pos)
{
    this->_old_pos = new_pos;
}

irr::core::vector3d<float> Chara_in_game::get_pos()
{
    return (this->_pos);
}

irr::core::vector3d<float> Chara_in_game::get_old_pos()
{
    return (this->_old_pos);
}

void Chara_in_game::move_player(direction what_you_want_to_go)
{
    if (what_you_want_to_go == direction::UP_D) {
        this->_direction = what_you_want_to_go;
        this->_pos.Y = this->_pos.Y + 3;
    } else if (what_you_want_to_go == direction::DOWN_D) {
        this->_direction = what_you_want_to_go;
        this->_pos.Y = this->_pos.Y - 3;
    } else if (what_you_want_to_go == direction::LEFT_D) {
        this->_direction = what_you_want_to_go;
        this->_pos.X = this->_pos.X + 3;
    } else if (what_you_want_to_go == direction::RIGHT_D) {
        this->_direction = what_you_want_to_go;
        this->_pos.X = this->_pos.X - 3;
    } else
        return;
    this->_animation = anim::RUN;
}
