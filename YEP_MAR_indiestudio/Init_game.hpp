/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef INIT_GAME_HPP_
#define INIT_GAME_HPP_

#include <irrlicht/irrlicht.h>
#include <map>

class Graphical;
class Input;
class Parametre;
class Graphical_menu;
class Graphical_game;
class Jukebox;

class Init_game {
    public:
        Init_game();
        ~Init_game();
        void start_game();

    protected:
        Input *_input;
        Graphical *_graphical;
        Parametre *_parametre;
        Jukebox *_jukebox;
        Graphical_menu *_graphical_menu;
        Graphical_game *_graphical_game;

        bool _game_pause;
        bool _win_pause;
        std::map<std::string, bool> _inputs;
    private:
};

#endif /* !INIT_GAME_HPP_ */
