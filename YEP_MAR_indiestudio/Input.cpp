/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Input.hpp"
#include <iostream>

Input::Input()
{
    this->_is_wait = true;
    this->_inputs["escape"] = false;
    this->_inputs["mouse_click_left"] = false;
    this->_inputs["mouse_click_right"] = false;
    this->_inputs["z"] = false; // avant J1
    this->_inputs["q"] = false; // gauche J1
    this->_inputs["s"] = false; // droite J1
    this->_inputs["d"] = false; // bas J1
    this->_inputs["e"] = false; // use J1
    this->_inputs["t"] = false; // avant J2
    this->_inputs["f"] = false; // gauche J2
    this->_inputs["g"] = false; // droite J2
    this->_inputs["h"] = false; // bas J2
    this->_inputs["y"] = false; // use J2
    this->_inputs["i"] = false; // avant J3
    this->_inputs["j"] = false; // gauche J3
    this->_inputs["k"] = false; // droite J3
    this->_inputs["l"] = false; // bas J3
    this->_inputs["o"] = false; // use J3
    this->_inputs["up_arrow"] = false; // avant J4
    this->_inputs["left_arrow"] = false; // gauche J4
    this->_inputs["down_arrow"] = false; // droite J4
    this->_inputs["right_arrow"] = false; // bas J4
    this->_inputs["right_shift"] = false;  // use J4

}

Input::~Input()
{
}


Input::state_mouse_on_asset Input::get_mousse_state(Asset2D *asset)
{
    // std::cout << "AAAAAAAAAAAAAA | " << asset->id << std::endl;
    // std::cout << "rect " /*<< asset->posX << " | " << asset->posY << " | "*/ << asset->posX + asset->img->getSize().Width << " | " << asset->posY + asset->img->getSize().Height << std::endl;
    irr::core::rect<int> new_rect =  irr::core::rect<int>(asset->posX, asset->posY, asset->posX + asset->img->getSize().Width,
                                                          asset->posY + asset->img->getSize().Height);
    // std::cout << "Mouse " << this->_pos_mouse.X << " | " << this->_pos_mouse.Y << std::endl;
    if (new_rect.isPointInside(this->_pos_mouse)) {
        if (this->_inputs["mouse_click_left"] != true)
            return (ON_FOCUS);
        else {
            if (this->_is_wait) {
                this->_inputs["mouse_click_left"] = true;
                this->_is_wait = false;
                return (ON_CLICK);
            }
            else
                this->_inputs["mouse_click_left"] = false;
            return (ALED);
        }
    }
    return (ALED);
}

bool Input::get_input(std::string input_name)
{
    return (_inputs[input_name]);
}

std::map<std::string, bool> Input::get_all_input()
{
    return (this->_inputs);
}

bool Input::OnEvent(const irr::SEvent& event)
{
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
        if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN) {
            this->_inputs["mouse_click_left"] = true;
        } if (event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP) {
            this->_is_wait = true;
            this->_inputs["mouse_click_left"] = false;
        } if (event.MouseInput.Event == irr::EMIE_MOUSE_MOVED) {
            this->_pos_mouse.X = event.MouseInput.X;
            this->_pos_mouse.Y = event.MouseInput.Y;
        }
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        if (event.KeyInput.Key == irr::KEY_ESCAPE)
            this->_inputs["escape"] = event.KeyInput.PressedDown;

        if (event.KeyInput.Key == irr::KEY_KEY_Z) // J1
            this->_inputs["z"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_Q)
            this->_inputs["q"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_S)
            this->_inputs["s"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_D)
            this->_inputs["d"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_E)
            this->_inputs["e"] = event.KeyInput.PressedDown;
        
        if (event.KeyInput.Key == irr::KEY_KEY_T) //J2
            this->_inputs["t"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_F)
            this->_inputs["f"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_G)
            this->_inputs["g"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_H)
            this->_inputs["h"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_Y)
            this->_inputs["y"] = event.KeyInput.PressedDown;
        
        if (event.KeyInput.Key == irr::KEY_KEY_I) //J3
            this->_inputs["i"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_J)
            this->_inputs["j"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_K)
            this->_inputs["k"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_L)
            this->_inputs["l"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_KEY_O)
            this->_inputs["o"] = event.KeyInput.PressedDown;

        if (event.KeyInput.Key == irr::KEY_UP) //J4
            this->_inputs["up_arrow"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_RIGHT)
            this->_inputs["right_arrow"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_DOWN)
            this->_inputs["down_arrow"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_LEFT)
            this->_inputs["left_arrow"] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == irr::KEY_RSHIFT)
            this->_inputs["right_shift"] = event.KeyInput.PressedDown;
}
