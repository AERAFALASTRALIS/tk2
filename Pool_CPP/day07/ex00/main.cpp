/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Skat.hpp"

int main()
{
    Skat s("bob", 15);

    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    return (0);
}
