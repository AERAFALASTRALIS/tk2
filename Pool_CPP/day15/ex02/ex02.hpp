/*
** EPITECH PROJECT, 2021
** ex02
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename X>
const X& min(const X& a, const X& b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

template<typename X>
const X& templateMin(const X* tmp, int size)
{
    X& low = const_cast<X&>(tmp[0]);
    for (int i = 1; i < size; i++) {
        low = min<X>(low, tmp[i]);
    }
    return (low);
}

int nonTemplateMin(int* tmp, int size)
{
    int low = tmp[0];
    for (int i = 1; i < size; i++) {
        low = min(low, tmp[i]);
    }
    return (low);
}

#endif
