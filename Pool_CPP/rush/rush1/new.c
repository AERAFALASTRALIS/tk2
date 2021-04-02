/*
 * EPITECH PROJECT, 2020
 * rush1
 * File description:
 * new.c
*/

#include "new.h"
#include <stdarg.h>
#include "raise.h"
#include <stdlib.h>

Object  *new(const Class *class, ...)
{
    va_list ap;
    Object *obj = NULL;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

Object  *va_new(const Class *class, va_list *ap)
{
    Object *obj = malloc(class->__size__);

    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *obj)
{
    if (!obj)
        return;
    if (((Class *) obj)->__dtor__)
        ((Class *) obj)->__dtor__(obj);
    free(obj);
}
