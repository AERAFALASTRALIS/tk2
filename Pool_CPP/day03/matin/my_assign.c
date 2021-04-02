/*
** EPITECH PROJECT, 2021
** assign
** File description:
** assign
*/

#include "string.h"

void assign_c(string_t *this, const char *s)
{
    int i = strlen(s);
    char *dest = malloc(sizeof(char) * (i+1));

    strcpy(dest, s);
    this->str = dest; 
}
