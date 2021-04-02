/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Teddy.hpp
*/

#include <iostream>
#include <string>

class Teddy {
    std::string title;
    public:
        Teddy(std::string title);
        ~Teddy();
        void isTaken();
}