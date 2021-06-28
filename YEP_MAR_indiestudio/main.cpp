/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Init_game.hpp"
#include <irrlicht/irrlicht.h>

int main(void)
{
    Init_game *init_game = new Init_game;

    init_game->start_game();

    // while (init_game->device->run()) {
    //     init_game->driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
    //     init_game->sceneManager->drawAll;
    //     init_game->driver->endScene ();
    // }
}
