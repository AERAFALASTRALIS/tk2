/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** testnbr
*/

#include "include/global.h"

int testnbr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
