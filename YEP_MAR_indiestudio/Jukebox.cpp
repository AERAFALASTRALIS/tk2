/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#include "Jukebox.hpp"
#include <iostream>

Jukebox::Jukebox()
{
    this->fill_map();
}

Jukebox::~Jukebox()
{
    this->stop_all_music();
    std::map<Jukebox_music, sf::Music>::iterator map_iterator;

    for (map_iterator = this->_map_music.begin(); map_iterator != this->_map_music.end(); map_iterator++) {
        (*map_iterator).second.~SoundStream();
        (*map_iterator).second.~SoundSource();
        (*map_iterator).second.~Music();
    }
    // for (int i = 0; i != Jukebox_music::LAST ; i = i + 1)
    //     this->_map_music.erase((Jukebox_music)i);
    this->_map_music.clear();
}

void Jukebox::fill_map()
{
    this->_map_music[Jukebox_music::MUSIC_MAIN_MENU].openFromFile("asset_graphical/sound/Title_music.flac");
    this->_map_music[Jukebox_music::MUSIC_MAIN_MENU].setLoop(true);
    this->_map_music[Jukebox_music::MUSIC_IN_GAME].openFromFile("asset_graphical/sound/Area_1_music.flac");
    this->_map_music[Jukebox_music::MUSIC_IN_GAME].setLoop(true);
    this->_map_music[Jukebox_music::SOUND_BUTTON_PLAY].openFromFile("asset_graphical/sound/play.wav");
    this->_map_music[Jukebox_music::SOUND_BUTTON_PLAY].setLoop(false);
}

void Jukebox::play_music(Jukebox_music what_type)
{
    if (this->_map_music[what_type].getStatus() != sf::Music::Playing) {
        this->_map_music[what_type].play();
        // this->_map_music[what_type].setLoop(true);
        // std::cout << this->_map_music[what_type].getLoop() << std::endl;
    }
}

void Jukebox::play_music_spaming(Jukebox_music what_type)
{
    this->_map_music[what_type].play();
}

void Jukebox::stop_all_music()
{
    // std::cout << "stop_all_music" << std::endl;
    std::map<Jukebox_music, sf::Music>::iterator map_iterator;

    for (map_iterator = this->_map_music.begin(); map_iterator != this->_map_music.end(); map_iterator++) {
        if ((*map_iterator).second.getStatus() != sf::Music::Stopped)
        (*map_iterator).second.stop();
    }
}
