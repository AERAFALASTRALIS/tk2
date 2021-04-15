/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i+1;
    }
}

int my_strcmp(const char *s1, const char *s2)
{
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) {
        s1 = s1 + 1;
        s2 = s2 + 1;
    }
    if (*s1 == *s2)
        return (0);
    else 
        return (*s1 - *s2);
}

void print_usage(void)
{
    my_putstr("USAGE: ./strace [-s] [-p <pid>|<command>]");
    my_putchar('\n');
}

void print_error(void)
{
    my_putstr("strace : l'option requiert un argument\n");
}
