/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void) this;
}

static char *Point_str(PointClass *this)
{
    char *str = malloc(128);

    if (str)
        snprintf(str, 128, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return (str);
}

static Object *Point_add(PointClass *this, PointClass *other)
{
    return (new(Point, this->x + other->x, this->y + other->y));
}

static Object *Point_sub(PointClass *this, PointClass *other)
{
    return (new(Point, this->x - other->x, this->y - other->y));
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)Point_add,
        .__sub__ = (binary_operator_t)Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
