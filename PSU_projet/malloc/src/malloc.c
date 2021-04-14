/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include "../include/my.h"

void *malloc(size_t size)
{
    void *ptr;
    ptr = sbrk(0);
    if (sbrk(size) == (void *)-1)
        return (NULL);
    return (ptr);
}
