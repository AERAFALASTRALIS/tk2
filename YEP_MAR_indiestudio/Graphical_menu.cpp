/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Graphical_menu.hpp"
#include <iostream>

Graphical_menu::Graphical_menu(Graphical *graphical, Parametre *parametre, Jukebox *jukebox)
{
    this->_graphical = graphical;
    this->_parametre = parametre;
    this->_jukebox = jukebox;
    this->_input = graphical->get_input();
    this->_what_scene = MAIN_SCREEN;
    this->_quit_main_menu = false;
}

Graphical_menu::~Graphical_menu()
{
    this->_asset2d_id_list.clear();
}

bool Graphical_menu::get_quit_main_menu() const
{
    return (this->_quit_main_menu);
}

void Graphical_menu::creatbutton(Graphical::typeTexture texture, Graphical::typeTexture textureFocus, int pos_x, int pos_y, button_value scene, bool decalFocus)
{
    // std::cout << "o         " << (Graphical::typeTexture)texture << std::endl;
    this->_button_list.push_back(new Menu_bouton(this->_graphical->get_asset2D()->create2DAsset(texture, pos_x, pos_y), texture, textureFocus, this->_input, decalFocus, this->_graphical, scene, this->_jukebox));
}

void Graphical_menu::display_main_screen()
{
    // std::cout << "p         " << Graphical::MAIN_MENU_BACKGROUD << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::MAIN_MENU_BACKGROUD, 0, 0));
    // std::cout << "l         " << Graphical::MAIN_MENU_TITLE << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::MAIN_MENU_TITLE, 100, 100));
    this->creatbutton(Graphical::MAIN_MENU_BUTTON_PLAY, Graphical::MAIN_MENU_BUTTON_PLAY_OVER, SCREEN_WIDTH - BUTTON_WIDTH + 200, (SCREEN_HEIGHT / 2) - (BUTTON_HEIGHT) * 2 - 15 + 200, button_value::START, true);
    this->creatbutton(Graphical::MAIN_MENU_BUTTON_QUIT, Graphical::MAIN_MENU_BUTTON_QUIT_OVER, SCREEN_WIDTH - BUTTON_WIDTH + 200, (SCREEN_HEIGHT / 2) - (BUTTON_HEIGHT + 5) + 200, button_value::LEAVE, true);
    // std::cout << this->_asset2d_id_list.size() << '|' << this->_button_list.size() << std::endl;
}

void Graphical_menu::display_select_player()
{
    // std::cout << "m         " << Graphical::MAIN_MENU_BACKGROUD << std::endl;
    this->_asset2d_id_list.push_back(this->_graphical->get_asset2D()->create2DAsset(Graphical::MAIN_MENU_BACKGROUD, 0, 0));
    if (this->_player_select_list.empty())
        for (int i = 0; i < 4 ; i = i + 1)
            this->_player_select_list.push_back(new Player_select(i, this->_graphical, this->_input));
    this->creatbutton(Graphical::SELECT_BUTTON_PLAY, Graphical::SELECT_BUTTON_PLAY_OVER,  SCREEN_WIDTH - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_BUTTON_PLAY)->getSize().Width, SCREEN_HEIGHT - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_BUTTON_PLAY)->getSize().Height, button_value::START_GAME, false);
    this->creatbutton(Graphical::SELECT_BUTTON_RETURN, Graphical::SELECT_BUTTON_RETURN_OVER, 0, SCREEN_HEIGHT - this->_graphical->get_texture_by_typeTexture(Graphical::SELECT_BUTTON_RETURN_OVER)->getSize().Height, button_value::BACK, false);
    // std::cout << this->_asset2d_id_list.size() << '|' << this->_button_list.size() << std::endl;
    
}

void Graphical_menu::creatmenuAssets()
{
    if (this->_what_scene == MAIN_SCREEN) {
        // std::cout << "MAIN_SCREEN" << std::endl;
        this->display_main_screen();
    }
    if (this->_what_scene == SELECT_PLAYER) {
        // std::cout << "SELECT_PLAYER" << std::endl;
        this->display_select_player();
    }
}

int Graphical_menu::get_nb_robot()
{
    std::list<Player_select *>::iterator player_select_it;
    short actual_player = 0;
    short actual_robot = 0;

    for (player_select_it = this->_player_select_list.begin(); player_select_it != this->_player_select_list.end(); ++player_select_it) {
        if ((*player_select_it)->get_player_type() == Player_select::PlayerType::robot)
            actual_robot = actual_robot + 1;
        if ((*player_select_it)->get_player_type() != Player_select::PlayerType::afk && (*player_select_it)->get_player_type() != Player_select::PlayerType::robot)
            actual_player = actual_player + 1;
    }
    return (actual_robot);
}

bool Graphical_menu::check_player_in_select()
{
    std::list<Player_select *>::iterator player_select_it;
    short actual_player = 0;
    short actual_robot = 0;

    for (player_select_it = this->_player_select_list.begin(); player_select_it != this->_player_select_list.end(); ++player_select_it) {
        if ((*player_select_it)->get_player_type() == Player_select::PlayerType::robot)
            actual_robot = actual_robot + 1;
        if ((*player_select_it)->get_player_type() != Player_select::PlayerType::afk && (*player_select_it)->get_player_type() != Player_select::PlayerType::robot)
            actual_player = actual_player + 1;
    }
    if (actual_player < 1 && actual_robot < 1)
        return (false);
    return (true);
}

void Graphical_menu::start_the_real_game()
{
    std::list<Player_select *>::iterator player_select_it;

    for (player_select_it = this->_player_select_list.begin(); player_select_it != this->_player_select_list.end(); ++player_select_it) {
        this->_parametre->add_player_confing((*player_select_it));
    }    
}

bool Graphical_menu::change_actual_scene(Menu_bouton *actual_button)
{
    std::list<Player_select *>::iterator player_select_it;
    // std::cout << "OUI AVANT :" << this->_what_scene << std::endl;

    
    if (actual_button->_scene == button_value::START)
        this->_what_scene = SELECT_PLAYER;
    if (actual_button->_scene == button_value::LEAVE)
        this->_quit_main_menu = true;
    if (actual_button->_scene == button_value::BACK)
        this->_what_scene = MAIN_SCREEN;
    if (actual_button->_scene == button_value::START_GAME) {
        this->_what_scene = PLAY_GAME;
        if (this->check_player_in_select())
            this->start_the_real_game();
        else 
            return (false);
    }
    this->_asset2d_id_list.clear();
    for (player_select_it = this->_player_select_list.begin(); player_select_it != this->_player_select_list.end(); ++player_select_it) {
        // std::cout << "(*player_select_it)->del_asset3d();" << std::endl;
        (*player_select_it)->del_asset3d();
    }
    this->_player_select_list.clear();
    // std::cout << "OUI APRES :" << this->_what_scene << std::endl;
    return (true);
}

bool Graphical_menu::stayeventmenu()
{
    std::list<Menu_bouton *>::iterator menu_bouton_it;
    Input::state_mouse_on_asset mouse_state;

    for (menu_bouton_it = this->_button_list.begin(); menu_bouton_it != this->_button_list.end(); ++menu_bouton_it) {
        if ((*menu_bouton_it)->exec_action_mouse() && this->change_actual_scene((*menu_bouton_it)))
            return (true);
    } return (false);
}

void Graphical_menu::display()
{
    std::list<Player_select *>::iterator player_select_it;
    // std::list<Menu_bouton *>::iterator menu_bouton_it;

    while (this->_graphical->get_reload()) {
        // std::cout << "reload screen" << std::endl;
        this->_button_list.clear();
        // this->_player_select_list.clear();
        this->_graphical->get_asset2D()->destroyAll2DAsset();
        this->creatmenuAssets();
        // std::cout << "after creatmenuasset" << std::endl;
        this->_graphical->setreload(false);
    } if (this->stayeventmenu())
        this->_graphical->setreload(true);
    // std::cout << "after stayeventmenu" << std::endl;
    for (player_select_it = this->_player_select_list.begin(); player_select_it != this->_player_select_list.end(); ++player_select_it)
        (*player_select_it)->stay_event();
    // std::cout << "after for" << std::endl;
    this->_graphical->get_asset2D()->displayAll2DAsset();
    // std::cout << "after getasset2d" << std::endl;
    this->_graphical->drawAll();
    //  std::cout << "ALED" << std::endl;
}
