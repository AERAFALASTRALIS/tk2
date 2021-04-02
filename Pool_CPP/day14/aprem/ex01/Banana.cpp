/*
** EPITECH PROJECT, 2021
** banana
** File description:
** banana
*/

#include "Banana.hpp"

Banana::Banana() : Fruit("banana", 5)
{
}

Banana::~Banana()
{
}

std::string const &Banana::getName() const
{
  return (this->_name);
}
