/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** task 02
*/

#include "include/global.h"

int my_putstr(char const *str)
{
    int z = 0;
    while (str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
    return (0);
}
