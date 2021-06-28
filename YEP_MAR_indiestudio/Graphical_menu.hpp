/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef GRAPHICAL_MENU_HPP_
#define GRAPHICAL_MENU_HPP_

#include "Graphical.hpp"
#include "Parametre.hpp"
#include "Player_select.hpp"
#include "Menu_bouton.hpp"
#include "Jukebox.hpp"

#define BUTTON_HEIGHT (this->_graphical->get_texture_by_typeTexture(Graphical::MAIN_MENU_BUTTON_PLAY)->getSize().Height)
#define BUTTON_WIDTH (this->_graphical->get_texture_by_typeTexture(Graphical::MAIN_MENU_BUTTON_PLAY)->getSize().Width)

class Graphical_menu {
    public:

        enum actual_scene {
            MAIN_SCREEN,
            SELECT_PLAYER,
            PLAY_GAME,
            QUIT
        };

        Graphical_menu(Graphical *graphical, Parametre *parametre, Jukebox *jukebox);
        ~Graphical_menu();

        bool get_quit_main_menu() const;
        bool check_player_in_select();
        void start_the_real_game();
        int get_nb_robot();
        void display();
        void display_main_screen();
        void display_select_player();
        bool change_actual_scene(Menu_bouton *actual_button);
        bool stayeventmenu();
        void creatmenuAssets();
        void creatbutton(Graphical::typeTexture texture, Graphical::typeTexture textureFocus, int pos_x, int pos_y, button_value scene, bool decalFocus);

    protected:
        bool _quit_main_menu;
        std::list<unsigned> _asset2d_id_list;
        Graphical *_graphical;
        Parametre *_parametre;
        Input *_input;
        Jukebox *_jukebox;
        actual_scene _what_scene;
        std::list<Menu_bouton *> _button_list;
        std::list<Player_select *> _player_select_list;

    private:
};

#endif /* !GRAPHICAL_MENU_HPP_ */
