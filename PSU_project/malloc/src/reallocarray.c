/*
** EPITECH PROJECT, 2021
** reallocarray
** File description:
** reallocarray
*/

#include "../include/my.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    ptr = realloc(ptr, nmemb * size);
    return (ptr);
}
