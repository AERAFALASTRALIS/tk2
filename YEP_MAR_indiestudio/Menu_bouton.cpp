/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Menu_bouton.hpp"
#include <iostream>

Menu_bouton::Menu_bouton(unsigned id, Graphical::typeTexture texture, Graphical::typeTexture texture_on_focus, Input *inputs, bool decal_focus, Graphical *graphical, button_value scene, Jukebox *jukebox)
{
    this->_asset_id = id;
    this->_texture = texture;
    this->_texture_on_focus = texture_on_focus;
    this->_inputs = inputs;
    this->_decal_focus = decal_focus;
    this->_graphical = graphical;
    this->_scene = scene;
    this->_focus = false;
    this->_jukebox = jukebox;
}

Menu_bouton::~Menu_bouton()
{
    this->_graphical->get_asset2D()->destroy2DAsset(this->_asset_id);
}

Input::state_mouse_on_asset Menu_bouton::get_state() const
{
    return (this->_inputs->get_mousse_state(this->_graphical->get_asset2D()->getAsset2DById(this->_asset_id)));
}

bool Menu_bouton::exec_action_mouse()
{
    Input::state_mouse_on_asset actual_state = get_state();
	// std::cout << actual_state << " | " << this->_focus << " | " << this->_decal_focus << std::endl;

    if (actual_state == Input::ON_FOCUS && !this->_focus) {
        // std::cout << "ON_FOCUS" << std::endl;
        this->_jukebox->play_music_spaming(Jukebox_music::SOUND_BUTTON_PLAY);
        if (this->_decal_focus) {
            this->_graphical->get_asset2D()->modify2DAsset(this->_texture_on_focus, this->_asset_id,
                                                           SCREEN_WIDTH - this->_graphical->get_texture_by_typeTexture(this->_texture)->getSize().Width + 100, -1);
            // std::cout << "_decal_focus" << std::endl;
        }
        else {
            this->_graphical->get_asset2D()->modify2DAsset(this->_texture_on_focus, this->_asset_id);
            // std::cout << "_decal_focus_ouf" << std::endl;
        }
        this->_focus = true;
    } if (actual_state == Input::ALED && this->_focus) {
		// std::cout << "NONE" << std::endl;
        if (this->_decal_focus)
            this->_graphical->get_asset2D()->modify2DAsset(this->_texture, this->_asset_id, SCREEN_WIDTH - this->_graphical->get_texture_by_typeTexture(this->_texture)->getSize().Width + 200, -1);
        else
            this->_graphical->get_asset2D()->modify2DAsset(this->_texture, this->_asset_id);
        this->_focus = false;
    } if (actual_state == Input::ON_CLICK)
        return (true);
    return (false);
}

unsigned Menu_bouton::get_asset_id() const
{
    return (this->_asset_id);
}
