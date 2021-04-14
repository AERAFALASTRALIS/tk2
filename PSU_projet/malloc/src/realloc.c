/*
** EPITECH PROJECT, 2021
** realloc
** File description:
** realloc
*/

#include "../include/my.h"

void *realloc(void *ptr, size_t size)
{
    void *src;
    src = ptr;
    free(src);
    return (sbrk(size));	
}
