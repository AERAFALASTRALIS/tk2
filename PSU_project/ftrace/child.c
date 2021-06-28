/*
** EPITECH PROJECT, 2021
** child
** File description:
** child
*/

#include "my.h"

void exec_child(char *filename, char **av)
{
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execvp(filename, av);
}
