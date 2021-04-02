/*
** EPITECH PROJECT, 2021
** day 6
** File description:
** dy 6
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>


void checkarg(char *str)
{
    std::ifstream fs;
    char buffer;

    fs.open(str, std::fstream::in);
    if(fs) {
        while (!fs.eof()) {
            buffer = (char) fs.get();
            if (buffer != -1)
                std::cout << buffer;
        }
    } else
        std::cerr << "my_cat: " << str << ": No such file or directory" << std::endl;
    fs.close();
}


int main(int ac, char **av)
{
    int i = 1;

    if(ac < 2) {
        std::cerr << "my_cat: Usage: "<< av[0] << " file [...]"<< std::endl;
        return (1);
    }
    while(av[i]) {
        checkarg(av[i]);
        i++;
    }
    return (0);
}
