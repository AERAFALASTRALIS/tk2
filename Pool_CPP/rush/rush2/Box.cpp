/*
** EPITECH PROJECT, 2021
** box
** File description:
** box
*/

#include "Box.hpp"

Box::Box(std::string const &name) : Wrap(name, "box")
{

}

Box::~Box() {}

void Box::wrapMeThat(Object* obj) {
    if(this->_isOpen) {
        Wrap::wrapMeThat(obj);
        this->_isOpen = false;
    }
}

void Box::closeMe() {
    this->_isOpen = false;
}
