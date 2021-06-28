/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Assets2DHandler.hpp"

#include <IEventReceiver.h>
#include <position2d.h>
#include <map>

class Input : public irr::IEventReceiver {

    public:
        enum state_mouse_on_asset {
            ON_FOCUS,
            ON_CLICK,
            ALED
        };
    
        Input();
        ~Input();
        virtual bool OnEvent(const irr::SEvent& event);
        state_mouse_on_asset get_mousse_state(Asset2D *asset);
        bool get_input(std::string input_name);
        std::map<std::string, bool> get_all_input();

    protected:
        bool _is_wait;
        std::map<std::string, bool> _inputs;
        irr::core::position2di _pos_mouse;
    private:
};

#endif /* !INPUT_HPP_ */
