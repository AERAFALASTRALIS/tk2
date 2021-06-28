/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-antoine.viala
** File description:
** Player_select
*/

#ifndef JUKEBOX_HPP_
#define JUKEBOX_HPP_

#include <SFML/Audio.hpp>
#include <map>

enum Jukebox_music {
    MUSIC_MAIN_MENU,
    MUSIC_IN_GAME,
    SOUND_BUTTON_PLAY,
    LAST, // laisser le last en dernier pos
};

// enum Jukebox_button_sound {
//     SOUND_BUTTON,
// };

class Jukebox {
    public:
        Jukebox();
        ~Jukebox();

        void fill_map();
        void play_music(Jukebox_music what_type);
        void play_music_spaming(Jukebox_music what_type);
        void stop_music();
        void stop_all_music();
    protected:
        std::map<Jukebox_music, sf::Music> _map_music;
    private:
};

#endif /* !JUKEBOX_HPP_ */
