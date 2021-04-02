/*
** EPITECH PROJECT, 2021
** Picture
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string& file)
{
    this->getPictureFromFile(file);
}

Picture::~Picture()
{

}

bool Picture::getPictureFromFile(const std::string& file)
{
    std::ifstream File;
    char tmp;
    std::string stok;

    File.open(file.c_str(), std::fstream::in);
    if (File)
    {
        while (!File.eof())
        {
            tmp = (char) File.get();
            if (tmp != -1)
                stok += tmp;
        }
    } else {
        this->data = "ERROR";
        return (false);
    }
    this->data = stok;
    File.close();
    return (true);
}
