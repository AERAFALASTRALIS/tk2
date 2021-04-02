/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "int.h"
#include <stdbool.h>
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void) this;
}

static char *Int_str(IntClass *this)
{
    char *str = malloc(40);

    if (str)
        snprintf(str, 40, "<%s (%d)>", this->base.__name__, this->x);
    return (str);
}

static Object *Int_add(IntClass *this, IntClass *other)
{
    return (new(Int, this->x + other->x));
}

static Object *Int_sub(IntClass *this, IntClass *other)
{
    return (new(Int, this->x - other->x));
}

static Object *Int_mul(IntClass *this, IntClass *other)
{
    return (new(Int, this->x * other->x));
}

static Object *Int_div(IntClass *this, IntClass *other)
{
    return (new(Int, this->x / other->x));
}

static bool Int_eq(IntClass *this, IntClass *other)
{
    return (this->x == other->x);
}

static bool Int_gt(IntClass *this, IntClass *other)
{
    return (this->x > other->x);
}

static bool Int_lt(IntClass *this, IntClass *other)
{
    return (this->x < other->x);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)Int_add,
        .__sub__ = (binary_operator_t)Int_sub,
        .__mul__ = (binary_operator_t) Int_mul,
        .__div__ = (binary_operator_t) Int_div,
        .__eq__ = (binary_comparator_t) Int_eq,
        .__gt__ = (binary_comparator_t) Int_gt,
        .__lt__ = (binary_comparator_t) Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
