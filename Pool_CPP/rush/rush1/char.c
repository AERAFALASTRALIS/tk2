/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void) this;
}

static char *Char_str(CharClass *this)
{
    char *str = malloc(40);

    if (str)
        snprintf(str, 40, "<%s (%c)>", this->base.__name__, this->x);
    return (str);
}

static Object *Char_add(CharClass *this, CharClass *other)
{
    return (new(Char, this->x + other->x));
}

static Object *Char_sub(CharClass *this, CharClass *other)
{
    return (new(Char, this->x - other->x));
}

static Object *Char_mul(CharClass *this, CharClass *other)
{
    return (new(Char, this->x * other->x));
}

static Object *Char_div(CharClass *this, CharClass *other)
{
    return (new(Char, this->x / other->x));
}

static bool Char_eq(CharClass *this, CharClass *other)
{
    return (this->x == other->x);
}

static bool Char_gt(CharClass *this, CharClass *other)
{
    return (this->x > other->x);
}

static bool Char_lt(CharClass *this, CharClass *other)
{
    return (this->x < other->x);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)Char_add,
        .__sub__ = (binary_operator_t)Char_sub,
        .__mul__ = (binary_operator_t) Char_mul,
        .__div__ = (binary_operator_t) Char_div,
        .__eq__ = (binary_comparator_t) Char_eq,
        .__gt__ = (binary_comparator_t) Char_gt,
        .__lt__ = (binary_comparator_t) Char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;
