/*
** EPITECH PROJECT, 2021
** nul
** File description:
** add
*/

#include <stdio.h>

void add_mul_4param(int first, int second, int* sum, int* product)
{
    *sum = (first + second);
    *product = (first * second);
}

void add_mul_2param(int* first, int* second)
{
    int somme = *first;
    int product = *second;
    
    *first = (somme + product);
    *second = (somme * product);
}
