/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef PARAMETRE_HPP_
#define PARAMETRE_HPP_

#include "Graphical.hpp"
#include <vector2d.h>
#include <map>
#include <list>

enum key_for_player {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    USE,
};

// enum direction {
//     UP_D = 0,
//     DOWN_D = 1,
//     LEFT_D = 2,
//     RIGHT_D = 3
// };

struct Player_config {
    bool robot;
    Graphical::typeObj model_chara;
    std::map<key_for_player, std::string> key;
};

class Player_select;

class Parametre {
    public:
        static const int defaultScreenWidth = 1920;// 1920;800
        static const int defaultScreenHeight = 1080;// 1080;500

        Parametre();
        ~Parametre();
        irr::core::vector2d<int> get_resolution() const;
        std::list<Player_config *> get_Player_config_list() const;
        
        void add_player_confing(Player_select *oui);
        void create_Player_Config(std::string up, std::string down, std::string left, std::string right, std::string use, bool robot, int model_chara);

    protected:
        irr::core::vector2d<int> _resolution;
        std::list<Player_config *> _Player_config_list;
    private:
};

#endif /* !PARAMETRE_HPP_ */
