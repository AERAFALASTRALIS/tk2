/*
** EPITECH PROJECT, 2021
** picture
** File description:
** picture
*/

#ifndef PICTURE_H_
#define PICTURE_H_

#include <fstream>
#include <iostream>

class Picture {
public:
    Picture();
    Picture(const std::string& file);
    ~Picture ();
    std::string data;
    bool getPictureFromFile(const std::string& file);
};

#endif

