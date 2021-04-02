/*
** EPITECH PROJECT, 2021
** find
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename X>
typename X::iterator do_find(X& file, int index)
{
    return std::find(file.begin(), file.end(), index);
}

#endif
