/*
** EPITECH PROJECT, 2021
** wrap
** File description:
** wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(std::string const & name, std::string const & type)
    : Object(name, "wrap"), _obj(NULL), _isOpen(false), _type(type) {
}

Wrap::~Wrap()
{
}

bool Wrap::isEmpty() const {
    return (!this->_obj);
}

bool Wrap::isOpen() const {
    return (this->_isOpen);
}

Object* Wrap::takeWrap() {
    if (!this->_obj)
        return NULL;
    Object *obj = this->_obj;

    this->_obj = NULL;
    this->_isOpen = true;
    std::cout << "whistles while working" << std::endl;
    return (obj);
}

void Wrap::openMe() {
    this->_isOpen = true;
}

void Wrap::wrapMeThat(Object *obj) {
    if (this->_obj)
        return;
    std::cout << "tuuuut tuuut tuut" << std::endl;
    this->_obj = obj;
}

std::string Wrap::getType() const {
    return (this->_type);
}
