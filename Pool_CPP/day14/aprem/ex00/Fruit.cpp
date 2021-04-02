/*
** EPITECH PROJECT, 2021
** fruit
** File description:
** fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string const &name, int vitamins) : _name(name), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

std::string const &Fruit::getName() const
{
  return (this->_name);
}

int Fruit::getVitamins() const
{
  return (this->_vitamins);
}

Fruit& Fruit::operator=(Fruit const& fruit)
{
  this->_name = fruit._name;
  this->_vitamins = fruit._vitamins;
  return (*this);
}

bool Fruit::operator==(Fruit const &fruit)
{
  if (this->_name == fruit.getName() && this->_vitamins == fruit.getVitamins())
    return (true);
  return (false);
}
