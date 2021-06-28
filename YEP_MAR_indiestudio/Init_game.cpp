/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Init_game.hpp"
#include "Input.hpp"
#include "Graphical.hpp"
#include "Parametre.hpp"
#include "Graphical_menu.hpp"
#include "Graphical_game.hpp"
#include "Jukebox.hpp"
# include <iostream>

Init_game::Init_game()
{
    this->_parametre = new Parametre();
    this->_input = new Input();
    this->_graphical = new Graphical(this->_input);
    this->_jukebox = new Jukebox();
    this->_win_pause = false;
    this->_game_pause = false;
}

Init_game::~Init_game()
{

}

void Init_game::start_game()
{
    while ((this->_graphical->getdevice()->run() && this->_graphical->getdriver()) == true) {
        if (this->_graphical->getdevice()->isWindowActive() == true) {
            this->_graphical->getdriver()->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));
            if (this->_graphical->get_actual_scene() == 0) { // lucnch menu
                this->_graphical->set_actual_scene(1);
                this->_graphical->add_camera_in_scene_manager(irr::core::vector3df(0, 0, -300), irr::core::vector3df(0, 0, 0));
                this->_win_pause = false;
                this->_game_pause = false;
                this->_inputs["space"] = false;
                this->_inputs["escape"] = false;
                this->_parametre->get_Player_config_list().clear();
                if (!this->_graphical_menu)
                    this->_graphical_menu = new Graphical_menu(this->_graphical, this->_parametre, this->_jukebox);
            }
            if (this->_graphical->get_actual_scene() == 1) { // menu
                // std::cout << "MENU" << std::endl;
                // this->_jukebox->stop_all_music();
                this->_jukebox->play_music(Jukebox_music::MUSIC_MAIN_MENU);
                this->_game_pause = false;
                this->_graphical_menu->display();
                if (this->_parametre->get_Player_config_list().size()) {
                    if (!this->_graphical_game)
                        this->_graphical_game = new Graphical_game(this->_graphical, this->_parametre, this->_graphical_menu->get_nb_robot());
                    this->_graphical->set_actual_scene(2);
                    this->_jukebox->stop_all_music();
                }
            }
            if (this->_graphical->get_actual_scene() == 2) { // game
                this->_jukebox->play_music(Jukebox_music::MUSIC_IN_GAME);
                if (!this->_graphical_game)
                    this->_graphical_game = new Graphical_game(this->_graphical, this->_parametre, this->_graphical_menu->get_nb_robot());
                if (this->_game_pause) {
                    this->_graphical_game->display_pause();
                } else {
                    this->_graphical_game->display();
                }
            }
            if (this->_graphical_menu && this->_graphical_menu->get_quit_main_menu()) {
                this->_jukebox->stop_all_music();
                return;
            }
            if (!this->_win_pause) {
                if (this->_input->get_input("escape")) {
                    if (!this->_inputs["escape"]) {
                        if (this->_graphical_game)
                            this->_game_pause = !this->_game_pause;
                        this->_inputs["escape"] = true;
                    }
                } else {
                    this->_inputs["escape"] = false;
                }
            }
            this->_graphical->end_scene();
        }
    }
    this->_jukebox->stop_all_music();
}
