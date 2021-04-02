/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct ListIterator_s {
    Iterator base;
    ListClass *_list;
    ListChain *_chain;
}   ListIteratorClass;

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_chain = va_arg(*args, ListChain *);
}

static bool     ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_chain == other->_chain);
}

static bool     ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_chain > other->_chain);
}

static bool     ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_chain < other->_chain);
}

static void     ListIterator_incr(ListIteratorClass *this)
{
    if (this->_chain == NULL)
        raise("Iterator out of range");
    this->_chain = this->_chain->next;
}

static void     ListIterator_decr(ListIteratorClass *this)
{
    if (this->_chain == NULL)
        raise("Iterator out of range");
    this->_chain = this->_chain->prev;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_chain == NULL)
        raise("Iterator out of range");
    return (this->_chain->obj);
}

static void     ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list ap;

    if (this->_chain == NULL)
        raise("Iterator out of range");
    va_start(ap, this);
    delete(this->_chain->obj);
    this->_chain->obj = va_new(this->_list->_type, &ap);
    va_end(ap);
}

static const ListIteratorClass   ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__decr__ = (decr_t)&ListIterator_decr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._chain = NULL
};

static const Class    *ListIterator = (const Class *)&ListIteratorDescr;

static void     List_ctor(ListClass *this, va_list *args)
{
    this->_type = va_arg(*args, Class *);
}

static void     List_dtor(ListClass *this)
{
    while (this->_size)
        pop_front(this);
}

static size_t   List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, this->_front));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, NULL));
}

static Object   *List_getitem(ListClass *this, ...)
{
    size_t index;
    va_list ap;
    ListChain *chain = this->_front;

    va_start(ap, this);
    index = va_arg(ap, size_t);
    va_end(ap);
    if (index >= this->_size)
        raise("Out of range");
    while (index-- > 0)
        chain = chain->next;
    return (chain->obj);
}

static void     List_setitem(ListClass *this, ...)
{
    size_t index;
    va_list ap;
    ListChain *chain = this->_front;

    va_start(ap, this);
    index = va_arg(ap, size_t);
    if (index >= this->_size) {
        va_end(ap);
        raise("Out of range");
    }
    while (index-- > 0)
        chain = chain->next;
    delete(chain->obj);
    chain->obj = va_new(this->_type, &ap);
    va_end(ap);
}

static void p_back(ListClass *this, va_list *ap)
{
    ListChain *chain = malloc(sizeof(*chain));

    if (this->_back == NULL) {
        chain->prev = NULL;
        this->_front = chain;
    } else {
        chain->prev = this->_back;
        this->_back->next = chain;
    }
    this->_back = chain;
    chain->next = NULL;
    chain->obj = va_new(this->_type, ap);
    this->_size++;
}

static void p_front(ListClass *this, va_list *ap)
{
    ListChain *chain;

    if (this->_front == NULL) {
        p_back(this, ap);
        return;
    }
    chain = malloc(sizeof(*chain));
    chain->next = this->_front;
    this->_front->prev = chain;
    this->_front = chain;
    chain->prev = NULL;
    chain->obj = va_new(this->_type, ap);
    this->_size++;
}

static void List_push_front(ListClass *this, ...)
{
    va_list ap;

    va_start(ap, this);
    p_front(this, &ap);
    va_end(ap);
}

static void List_push_back(ListClass *this, ...)
{
    va_list ap;

    va_start(ap, this);
    p_front(this, &ap);
    va_end(ap);
}

static void List_pop_front(ListClass *this)
{
    ListChain *chain;

    if (this->_front == NULL)
        raise("List is empty");
    chain = this->_front->next;
    delete(this->_front->obj);
    free(this->_front);
    this->_front = chain;
    if (this->_front == NULL)
        this->_back = NULL;
}

static void List_pop_back(ListClass *this)
{
    ListChain *chain;

    if (this->_back == NULL)
        raise("List is empty");
    chain = this->_back->next;
    delete(this->_back->obj);
    free(this->_back);
    this->_back = chain;
    if (this->_back == NULL)
        this->_front = NULL;
}

static void List_insert(ListClass *this, ListIteratorClass *position, ...)
{
    va_list ap;
    ListChain *chain;

    va_start(ap, position);
    if (position->_chain == NULL) {
        p_back(this, &ap);
    } else if (position->_chain == this->_front) {
        p_front(this, &ap);
    } else {
        chain = malloc(sizeof(*chain));
        if (!chain)
            raise("Out of memory");
        chain->next = position->_chain;
        chain->prev = chain->next->prev;
        chain->next->prev = chain;
        chain->obj = new(this->_type);
        this->_size++;
    }
    va_end(ap);
}

static Object *List_front(ListClass *this)
{
    return (NULL);
}

static Object *List_back(ListClass *this)
{
    return (NULL);
}

static Object **List_data(ListClass *this)
{
    if (this->_front)
        return (&this->_front->obj);
    return (NULL);
}

static const ListClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
        .__front__ = (direct_t)&List_front,
        .__back__ = (direct_t)&List_back,
        .__data__ = (data_t)&List_data,
    },
    ._type = NULL,
    ._size = 0,
    ._front = NULL,
    ._back = NULL,
    .__pushfront__ = List_push_front,
    .__pushback__ = List_push_back,
    .__popfront__ = List_pop_front,
    .__popback__ = List_pop_back,
    .__insert__ = List_insert
};

const Class   *List = (const Class *)&_descr;
