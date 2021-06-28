/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef MENU_BOUTON_HPP_
#define MENU_BOUTON_HPP_

#include "Graphical.hpp"
#include "Input.hpp"
#include "Jukebox.hpp"

enum button_value {
    START,
    LEAVE,
    BACK,
    RESUME,
    START_GAME,
    ALED
};

class Menu_bouton {
    public:
        Menu_bouton(unsigned id, Graphical::typeTexture texture, Graphical::typeTexture texture_on_focus, Input *inputs, bool decal_focus, Graphical *graphical, button_value scene, Jukebox *jukebox);
        ~Menu_bouton();
        Input::state_mouse_on_asset get_state() const;
        bool exec_action_mouse();
        unsigned get_asset_id() const;

        button_value _scene;

    protected:
        unsigned		_asset_id;
        Graphical::typeTexture	_texture;
        Graphical::typeTexture	_texture_on_focus;
        Assets2DHandler		*_assets2D;
        bool _focus;
        Input *_inputs;
        bool _decal_focus;
        Graphical *_graphical;
        Jukebox *_jukebox;
    private:
};

#endif /* !MENU_BOUTON_HPP_ */
