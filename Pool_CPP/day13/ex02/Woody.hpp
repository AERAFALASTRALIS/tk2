/*
** EPITECH PROJECT, 2021
** woodi
** File description:
** woodi
*/

#ifndef WOODY_H_
#define WOODY_H_

#include "Toy.hpp"
#include <iostream>

class Woody : public Toy {
	public:
	Woody(std::string const &name, std::string const &filename = "woody.txt");
	~Woody();
};

#endif
