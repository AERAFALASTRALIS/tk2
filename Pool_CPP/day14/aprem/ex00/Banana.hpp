/*
** EPITECH PROJECT, 2021
** banana
** File description:
** banana
*/

#ifndef BANANA_H_
#define BANANA_H_

#include <iostream>
#include "Fruit.hpp"

class Banana : public Fruit {
public:
  Banana();
  ~Banana();
  std::string const &getName() const;
};

#endif
