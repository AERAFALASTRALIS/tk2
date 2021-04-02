/*
** EPITECH PROJECT, 2021
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** Menu
*/

#include "menu.hpp"

Menu::Menu(sf::RenderWindow &window) : window(window)
{
    videoMode = {800, 600};

    _playTxt.resize(3);
    this->_playTxt[0] = "Jouer";
    this->_playTxt[1] = "Play";
    this->_playTxt[2] = "Jugar";
    this->_modLang = Menu::FR;

    this->window.create(videoMode, "Earth Defense");
    view.setViewport(sf::FloatRect(0, 0, 1, 1));
    initTexture();
}

void Menu::initTexture()
{
    Background.create(1920, 1080);
    Background.loadFromFile("textures/backgroundMenu.jpg");
    Background.setSmooth(true);
    SpriteBackground.setTexture(Background);
    SpriteBackground.setScale(0.6, 1);

    TextureButton.create(100, 50);
    TextureButton.loadFromFile("textures/Button.png");
    Font.loadFromFile("textures/space_age.ttf");
    TextButtonPlay.setFont(Font);

    if (this->_modLang == Menu::FR) TextButtonPlay.setString("Jouer");
    else if (this->_modLang == Menu::EN) TextButtonPlay.setString("Play");
    else if (this->_modLang == Menu::ES) TextButtonPlay.setString("Jugar");

    this->_TextureBtnSwipe.create(50, 50);
    this->_TextureBtnSwipe.loadFromFile("textures/icon.png");
    this->_TextSwitchBtn.setFont(Font);

    this->_TextSwitchBtn.setScale({2/1.5, 3.5/1.5});
    this->_TextSwitchBtn.setStyle(sf::Text::Bold);
    this->_ButtonSwitch.setTexture(this->_TextureBtnSwipe);
    this->posSwitch = {(float)videoMode.height / 2 + 100, (float)videoMode.width / 2 + 150};
    this->_TextSwitchBtn.setPosition({10, 770});
    this->_ButtonSwitch.setPosition(posSwitch);
    this->_ButtonSwitch.setScale({0.1, 0.1});

    TextButtonPlay.setScale({2, 3.5});
    TextButtonPlay.setStyle(sf::Text::Bold);
    ButtonPlay.setTexture(TextureButton);
    posButton = {(float)videoMode.height / 2, (float)videoMode.width / 2};
    TextButtonPlay.setPosition({posButton.x + 30, posButton.y - 10});
    ButtonPlay.setPosition(posButton);
    ButtonPlay.setScale({0.1, 0.1});
    _TextSwitchBtn.setString("Il faut proteger la Terre car\nc'est le seul monde habitable\nque nous avons");
}

void Menu::mainloop()
{
    const sf::Vector2i vec(800, 600);
    posSwitch.x -= 78;
    posSwitch.y -= 220;
    while (window.isOpen())
    {
        const auto tmp = souris.getPosition(window);
        const auto tmp2 = window.getSize();
        posSouris = sf::Vector2f(tmp.x * 800 / tmp2.x, tmp.y * 600 / tmp2.y);
        while (window.pollEvent(event))
        {

            if (posSouris.x >= ButtonPlay.getPosition().x && posSouris.x <= ButtonPlay.getPosition().x + 150 && posSouris.y >= posButton.y - 140 && posSouris.y <= posButton.y - 90)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    // add fonction pour changer de screen
                    return;
                }
            }

            if (posSouris.x >= posSwitch.x && posSouris.x <= posSwitch.x + 80 && posSouris.y >= posSwitch.y && posSouris.y <= posSwitch.y + 64)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (this->_modLang == Menu::FR) {

                        this->_modLang = Menu::EN;
                        this->TextButtonPlay.setString("Play");
                        _TextSwitchBtn.setString("We must protect the Earth\nbecause it is the only\nhabitable world we have");
                    } else if (this->_modLang == Menu::EN){

                        this->_modLang = Menu::ES;
                        this->TextButtonPlay.setString("Jugar");
                        _TextSwitchBtn.setString("Debemos proteger la Tierra\nporque es el unico\nmundo habitable que tenemos");
                    } else if (this->_modLang == Menu::ES) {

                        this->_modLang = Menu::FR;
                        this->TextButtonPlay.setString("Jouer");
                        _TextSwitchBtn.setString("Il faut proteger la Terre car\nc'est le seul monde habitable\nque nous avons");
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        Draw();
    }
}

void Menu::Draw()
{
    window.clear();
    window.draw(SpriteBackground);
    window.draw(ButtonPlay);
    window.draw(TextButtonPlay);
    window.draw(this->_ButtonSwitch);
    window.draw(_TextSwitchBtn);
    window.setView(view);
    window.display();
}

Menu::~Menu()
{
}
