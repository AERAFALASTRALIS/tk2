/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

void my_putcher(char c);
int my_putstr(char const *str);
int my_strcmp(const char *s1, const char *s2);
void print_usage(void);
void print_error(void);
    

#endif /* MY_H */

