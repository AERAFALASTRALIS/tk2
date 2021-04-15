/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct block {
    struct block_t *next;
    size_t size;
    void *ptr;
    bool result;
}block_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MY_H */
