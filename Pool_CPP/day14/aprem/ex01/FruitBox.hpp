/*
** EPITECH PROJECT, 2021
** fruitbox
** File description:
** fruitbox
*/

#ifndef FRUITBOX_H_
#define FRUITBOX_H_

#include <iostream>
#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
public:
  FruitBox(int size);
  ~FruitBox();
  int nbFruits() const;
  bool putFruit(Fruit* f);
  Fruit* pickFruit();
  FruitNode* head() const;
protected:
  int _size;
  int _count;
  FruitNode* header;
};

#endif
