/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** LittlePony.hpp
*/

#include <iostream>
#include <string>
#include "Toy.hpp"

class LittlePony : public Toy {
    std::string title;
    public:
        LittlePony(std::string title);
        ~LittlePony();
        void isTaken();
};
