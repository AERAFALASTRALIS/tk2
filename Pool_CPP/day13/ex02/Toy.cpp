/*
** EPITECH PROJECT, 2021
** toy
** File description:
** toy
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
  this->_picture.data = "";
}

Toy::Toy(ToyType type, std::string const &name, std::string const &ascii) : _type(type), _name(name), _picture(ascii)
{

}

Toy::~Toy()
{

}

int Toy::getType() const
{
  return (this->_type);
}

std::string const &Toy::getName() const
{
  return (this->_name);
}

std::string const &Toy::getAscii() const
{
  return (this->_picture.data);
}

void Toy::setName(std::string const &name)
{
  this->_name = name;
}

void Toy::setAscii(std::string const &picture)
{
  this->_picture.getPictureFromFile(picture);
}
