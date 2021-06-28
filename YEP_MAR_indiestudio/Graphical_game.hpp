/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef GRAPHICAL_GAME_HPP_
#define GRAPHICAL_GAME_HPP_

#include "Graphical.hpp"
#include "Parametre.hpp"
#include <ctime>
#include <vector>

// class Chara_in_game;

class Graphical_game {
    public:
        Graphical_game(Graphical *graphical, Parametre *parametre, int robot);
        ~Graphical_game();

        bool placeBox();
        bool isBlocked_Up(irr::core::vector3df pos);
        bool isBlocked_Down(irr::core::vector3df pos);
        bool isBlocked_Left(irr::core::vector3df pos);
        bool isBlocked_Right(irr::core::vector3df pos);
        void display();
        void create_game_asset();
        void deplacement();
        void display_pause();
        void create_player(Graphical::typeObj arg1, Player_config player_config);
        void checkDamage(irr::core::vector3df pos);
        void killPlayerByPos(irr::core::vector3df pos);
        void destroyBomb(irr::core::vector3df pos);
    protected:
        std::list<unsigned> background;
        int _nb_in_list;
        std::map<int, Graphical::typeObj> _map_what_player;
        int _nb_player;
        std::list<unsigned> _list_pause;
        std::map<Graphical::typeObj, int> _map_robot_typeObj_id;
        std::map<Graphical::typeObj, int> _map_player_typeObj_id;
        std::map<Graphical::typeObj, bool> _type_robot;
        std::map<Graphical::typeObj, Player_config> _map_player_typeObj_Player_config;
        std::map<Graphical::typeObj, int> _povX;
        std::map<Graphical::typeObj, int> _povY;
        std::map<Graphical::typeObj, int> _ammo;
        std::map<Graphical::typeObj, int> _boom;
        std::map<Graphical::typeObj, int> _hp;
        std::map<Graphical::typeObj, irr::core::vector3df> _boom_pos;
        std::map<Graphical::typeObj, irr::core::vector3df> _map_start_pos;
        std::map<Graphical::typeObj, irr::core::vector3df> _map_old_pos;
        // std::vector<Chara_in_game> _vector_player;
        int _asset3d_id_list;
        irr::core::vector3df pos;
        irr::core::vector3df posM;
        irr::core::vector3df posB;
        Graphical *_graphical;
        Parametre *_parametre;
        Input *_input;
        irr::ITimer *timer;
        int result;
        int boom;
        float posY;
        float posX;
        float posZ;

    private:
};

#endif /* !GRAPHICAL_GAME_HPP_ */
