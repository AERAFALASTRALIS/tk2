/*
** EPITECH PROJECT, 2021
** my_string
** File description:
** my_string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    int i = strlen(s);
    char *dest = malloc(sizeof(char) * (i+1));

    strcpy(dest, s);
    this->str = dest;
}

void string_destroy(string_t *this)
{
    free(this->str);
}
