/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "new.h"
#include "int.h"
#include "char.h"
#include "float.h"

void     compareAndDivide(Object *a, Object *b){if (gt(a, b))printf ("a > b\n");else if (lt(a, b))printf ("a < b\n");else printf ("a == b\n");printf ("b / a = %s\n", str(division(b, a)));}

int main(void) {
    compareAndDivide(new(Float, 10.f), new(Float, 5.f));
    compareAndDivide(new(Float, 5.f), new(Float, 10.f));
    compareAndDivide(new(Float, 10.f), new(Float, 10.f));
    compareAndDivide(new(Int, 10), new(Int, 5));
    compareAndDivide(new(Int, 5), new(Int, 10));
    compareAndDivide(new(Int, 10), new(Int, 10));
    compareAndDivide(new(Char, 10), new(Char, 5));
    compareAndDivide(new(Char, 5), new(Char, 10));
    compareAndDivide(new(Char, 10), new(Char, 10));
    return 0;
}
