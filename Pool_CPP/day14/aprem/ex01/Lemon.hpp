/*
** EPITECH PROJECT, 2021
** lemon
** File description:
** lemon
*/

#ifndef LEMON_H_
#define LEMON_H_

#include <iostream>
#include "Fruit.hpp"

class Lemon : public Fruit {
public:
  Lemon();
  ~Lemon();
  std::string const &getName() const;
};

#endif
