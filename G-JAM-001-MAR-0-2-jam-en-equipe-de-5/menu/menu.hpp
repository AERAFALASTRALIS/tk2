/*
** EPITECH PROJECT, 2021
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Menu
*/

#ifndef Menu_HPP_
#define Menu_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "./../story/Story.hpp"
class Menu {

    enum Lang {

        FR = 0,
        EN = 1,
        ES = 2
    };

    public:
        Menu(sf::RenderWindow &window);
        void mainloop();
        void initTexture();
        void Draw();

        void switchLang();
        ~Menu();

    private:
        sf::View view;
        sf::RenderWindow &window;
        sf::Event event;
        sf::Texture TextureButton;
        sf::Sprite ButtonPlay;
        sf::Text TextButtonPlay;
        sf::Font Font;
        sf::Texture Background;
        sf::Sprite SpriteBackground;
        sf::VideoMode videoMode;
        sf::Mouse souris;
        sf::Vector2f posSouris;
        sf::Vector2f posButton;
        sf::Vector2f posSwitch;

        sf::Sprite _ButtonSwitch;
        sf::Texture _TextureBtnSwipe;
        sf::Text _TextSwitchBtn;

        std::vector<std::string> _playTxt;

        Lang _modLang;
};

#endif /* !Menu_HPP_ */
