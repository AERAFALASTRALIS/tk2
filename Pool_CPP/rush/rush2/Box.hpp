/*
** EPITECH PROJECT, 2021
** box
** File description:
** box
*/

#ifndef BOX_H_
#define BOX_H_

#include <iostream>
#include "Wrap.hpp"

class Box : public Wrap {
public:
    Box(std::string const &name);
    ~Box();
    void closeMe();
    void wrapMeThat(Object *obj);
};

#endif
