/*
** EPITECH PROJECT, 2021
** ex00
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename X>
void swap(X& a, X& b)
{
    X c;
    c = a;
    a = b;
    b = c;
}

template<typename X>
const X& min(const X& a, const X& b)
{
    if (a <= b)
        return (a);
    return (b);
}

template<typename X>
const X& max(const X& a, const X& b)
{
    if (a >= b)
        return (a);
    return (b);
}

template<typename X>
X add(const X& a, const X& b)
{
    return (a + b);
}

#endif
