/*
** EPITECH PROJECT, 2021
** fruitbox
** File description:
** fruitbox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _count(0), header(NULL)
{
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
  return (this->_count);
}

bool FruitBox::putFruit(Fruit* f)
{
  if (!f)
    return (false);
  if (this->_count < this->_size)
  {
    FruitNode* node = new FruitNode();
    FruitNode* tmp;
    FruitNode* prev = 0;
    tmp = this->header;
    while (tmp)
    {
      if (tmp->_fruit == f)
        return (false);
      prev = tmp;
      tmp = tmp->next;
    }
    tmp = node;
    if (prev)
      prev->next = tmp;
    tmp->_fruit = f;
    tmp->next = NULL;
    if (!this->header)
      this->header = tmp;
    this->_count++;
    return (true);
  }
  return (false);
}

Fruit* FruitBox::pickFruit()
{
  if (this->_count)
  {
    FruitNode* del = this->header;
    Fruit* fruit = del->_fruit;
    this->header = this->header->next;
    delete del;
    this->_count--;
    return (fruit);
  }
  return (NULL);
}

FruitNode* FruitBox::head() const
{
  return (this->header);
}
