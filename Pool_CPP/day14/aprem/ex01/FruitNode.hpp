/*
** EPITECH PROJECT, 2021
** fruitnode
** File description:
** fruitnode
*/

#ifndef FRUITNODE_H_
#define FRUITNODE_H_

#include "Fruit.hpp"

struct FruitNode
{
  Fruit* _fruit;
  FruitNode *next;
};

#endif
