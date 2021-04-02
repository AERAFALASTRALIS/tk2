/*
** EPITECH PROJECT, 2021
** buzz
** File description:
** buzz
*/

#ifndef BUZZ_H_
#define BUZZ_H_

#include <iostream>
#include "Toy.hpp"

class Buzz : public Toy {
	public:
	Buzz(std::string const &name, std::string const &filename = "buzz.txt");
	~Buzz();
};

#endif
