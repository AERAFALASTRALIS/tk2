/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** task 07
*/

#include <unistd.h>
#include "include/global.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    else if (nb < 10) {
        my_putchar(nb+48);
    }
    else if (nb > 9){
        my_put_nbr(nb/10);
        my_put_nbr(nb%10);
    }
    return (0);
}
