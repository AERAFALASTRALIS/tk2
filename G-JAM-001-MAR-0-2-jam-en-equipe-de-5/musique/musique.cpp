/*
** EPITECH PROJECT, 2021
** musique
** File description:
** musique
*/

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

int musique_load(void)
{
	sf::Music music;
	if (!music.openFromFile("p1.ogg"))
	return (-1);
	//if (!music1.openFromFile("p4.mp3"))
	//return (-1);
	return (0);
}

