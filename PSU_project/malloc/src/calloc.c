/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** calloc
*/

#include "../include/my.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    ptr = sbrk(size * nmemb);
    memset(ptr, 0, size * nmemb);
    return (ptr);
}
