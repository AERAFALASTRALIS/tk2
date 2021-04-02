/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef LIST_H
# define LIST_H

# include "container.h"
#include "iterator.h"

typedef struct ListChain_s {
    Object *obj;
    struct ListChain_s *next;
    struct ListChain_s *prev;
} ListChain;

struct List_s;
struct ListIterator_s;

typedef void (*push_t)(struct List_s *this, ...);
typedef void (*pop_t)(struct List_s *this);
typedef void (*insert_t)(struct List_s *this, struct ListIterator_s *position, ...);

typedef struct List_s
{
    Container   base;
    Class       *_type;
    size_t      _size;
    ListChain *_front;
    ListChain *_back;
    push_t __pushfront__;
    push_t __pushback__;
    pop_t __popfront__;
    pop_t __popback__;
    insert_t __insert__;
}   ListClass;

# define push_front(list, ...)           ((ListClass *)list)->__pushfront__(list, _VA_ARGS__)
# define push_back(list, ...)           ((ListClass *)list)->__pushback__(list, _VA_ARGS__)
# define pop_front(list)           ((ListClass *)list)->__popfront__(list)
# define pop_back(list)           ((ListClass *)list)->__popback__(list)
# define insert(list, it, ...)           ((ListClass *)list)->__insert__(list, it, _VA_ARGS__)

extern const Class  *List;

#endif
