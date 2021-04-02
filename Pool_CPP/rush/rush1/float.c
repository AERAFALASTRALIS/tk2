/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void) this;
}

static char *Float_str(FloatClass *this)
{
    char *str = malloc(40);

    if (str)
        snprintf(str, 40, "<%s (%f)>", this->base.__name__, this->x);
    return (str);
}

static Object *Float_add(FloatClass *this, FloatClass *other)
{
    return (new(Float, this->x + other->x));
}

static Object *Float_sub(FloatClass *this, FloatClass *other)
{
    return (new(Float, this->x - other->x));
}

static Object *Float_mul(FloatClass *this, FloatClass *other)
{
    return (new(Float, this->x * other->x));
}

static Object *Float_div(FloatClass *this, FloatClass *other)
{
    return (new(Float, this->x / other->x));
}

static bool Float_eq(FloatClass *this, FloatClass *other)
{
    return (this->x == other->x);
}

static bool Float_gt(FloatClass *this, FloatClass *other)
{
    return (this->x > other->x);
}

static bool Float_lt(FloatClass *this, FloatClass *other)
{
    return (this->x < other->x);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)Float_add,
        .__sub__ = (binary_operator_t)Float_sub,
        .__mul__ = (binary_operator_t) Float_mul,
        .__div__ = (binary_operator_t) Float_div,
        .__eq__ = (binary_comparator_t) Float_eq,
        .__gt__ = (binary_comparator_t) Float_gt,
        .__lt__ = (binary_comparator_t) Float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;
