/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string
{
    char *str;

}string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);


#endif /*STRING_H_*/
