/*
** EPITECH PROJECT, 2021
** ex01
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <cstring>

template<typename X>
int compare(const X& a, const X& b)
{
    if (a == b)
        return (0);
    else if (a < b)
        return (-1);
    else
        return (1);
}

template<>
int compare<const char*>(const char* const &a, const char* const &b)
{
    if (strcmp(a, b) == 0)
        return (0);
    else if (strcmp(a, b) < 0)
        return (-1);
    else
        return (1);
}

#endif
