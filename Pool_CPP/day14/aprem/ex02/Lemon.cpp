/*
** EPITECH PROJECT, 2021
** lemon
** File description:
** lemon
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3)
{
}

Lemon::~Lemon()
{
}

std::string const &Lemon::getName() const
{
  return (this->_name);
}
