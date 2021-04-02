/*
** EPITECH PROJECT, 2021
** mem_ptr
** File description:
** mem_ptr
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int f = strlen(str1);
    int d = strlen(str2);
    char *tes = malloc(sizeof(char) * (f+d+1));
    char dest[f+1];
    char src[d+1];

    strcpy(dest, str1);
    strcpy(src, str2);
    strcat(tes, dest);
    strcat(tes, src);
    *res = tes;
}

void add_str_struct(str_op_t* str_op)
{
    add_str(str_op->str1, str_op->str2, &str_op->res);
}
