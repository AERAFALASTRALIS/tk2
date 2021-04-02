/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** main.cpp
*/
#include <iostream>
#include <string>
#include <cstring>
#include "core/Core.hpp"
#include "menu/menu.hpp"

int main(int argc, char const *argv[])
{
    // No arguments are handled yet
    Story gameStory;

    if (argc >= 2) {

        if (strcmp(argv[1], "-h_fr") == 0) {

            gameStory.getStory(0);
            exit(0);
        } else if (strcmp(argv[1], "-h_en") == 0) {

            gameStory.getStory(1);
            exit(0);
        } else if (strcmp(argv[1], "-h_es") == 0) {

            gameStory.getStory(2);
            exit(0);
        }
    }
    sf::RenderWindow window;

    Menu menu(window);
    Core core(window);
    do {
        menu.mainloop();
        core.mainloop();
    } while (core.keepAlive());
    return 0;
}
