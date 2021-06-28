/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Parametre.hpp"
#include "Player_select.hpp"

Parametre::Parametre()
{
    this->_resolution = irr::core::vector2d<int>(this->defaultScreenWidth, this->defaultScreenHeight);
}

Parametre::~Parametre()
{
}

irr::core::vector2d<int> Parametre::get_resolution() const
{
    return (this->_resolution);
}

std::list<Player_config *> Parametre::get_Player_config_list() const
{
   return (this->_Player_config_list);
}

void Parametre::add_player_confing(Player_select *oui)
{
    if (oui->get_player_type() == Player_select::Joueur1)
        this->create_Player_Config("z", "q", "s", "d", "e", false, oui->get_chara_chosed());
    else if (oui->get_player_type() == Player_select::Joueur2)
        this->create_Player_Config("t", "f", "g", "h", "y", false, oui->get_chara_chosed());
    else if (oui->get_player_type() == Player_select::Joueur3)
        this->create_Player_Config("i", "j", "k", "l", "o", false, oui->get_chara_chosed());
    else if (oui->get_player_type() == Player_select::Joueur4)
        this->create_Player_Config("up_arrow", "left_arrow", "down_arrow", "right_arrow", "right_shift", false, oui->get_chara_chosed());
    else
        this->create_Player_Config("", "", "", "", "", true, oui->get_chara_chosed());
}

void Parametre::create_Player_Config(std::string up, std::string down, std::string left, std::string right, std::string use, bool robot, int model_chara)
{
    Player_config *nouveau_joueur_de_tes_mort = new Player_config;

    nouveau_joueur_de_tes_mort->key[key_for_player::UP] = up;
    nouveau_joueur_de_tes_mort->key[key_for_player::DOWN] = down;
    nouveau_joueur_de_tes_mort->key[key_for_player::LEFT] = left;
    nouveau_joueur_de_tes_mort->key[key_for_player::RIGHT] = right;
    nouveau_joueur_de_tes_mort->key[key_for_player::USE] = use;
    nouveau_joueur_de_tes_mort->robot = robot;
    nouveau_joueur_de_tes_mort->model_chara = (Graphical::typeObj)model_chara;

    this->_Player_config_list.push_back(nouveau_joueur_de_tes_mort);
}
