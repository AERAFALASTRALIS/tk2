/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
static int gl_pid;

static char **get_syscalls(void)
{
    size_t ijls[4] = {0, 0, 0, 0,};
    FILE *fd;
    if ((fd = fopen("syscall_db", "r")) == NULL)
        return (NULL);
    ijls[3] = 50;
    char **ret = malloc(ijls[3] * sizeof(*ret));
    ijls[0] = 0;
    ret[ijls[0]] = NULL;
    while (getline(&ret[ijls[0]], &ijls[2], fd) != -1) {
        for (ijls[1] = 0; ret[ijls[0]][ijls[1]] &&
                 ret[ijls[0]][ijls[1]] != '\n'; ++ijls[1]);
        ret[ijls[0]][ijls[1]] = 0;
        if (++ijls[0] == ijls[3]) {
            ijls[3] += 50;
            if ((ret = realloc(ret, ijls[3] * sizeof(*ret))) == NULL)
                perror("realloc fail");
        }
        ret[ijls[0]] = NULL;
    }
    return (ret);
}

static int launch_progname(char **av)
{
    char **syscall_strtab;
    char *bin;

    syscall_strtab = get_syscalls();
    if (syscall_strtab == NULL)
        my_putstr("file syscall_db unreachable");
    if ((gl_pid = fork()) == -1)
        my_putstr("fork fail");
    if (!gl_pid)
        return (0);
     else
        return (0);
}

static int trace_pid(char **av)
{
    char **syscall_strtab;

    gl_pid = atoi(av[2]);
    if (gl_pid == 0 || gl_pid >= USHRT_MAX) {
        my_putstr("pid incorrect\n");
        return (84);
    }
    syscall_strtab = get_syscalls();
    if (syscall_strtab == NULL) {
        my_putstr("file syscall_db unreachable\n");
        return (84);
    }
    return (0);
}

void option(int ac, char **av)
{
    if(my_strcmp(av[1], "-p") == 0)
        trace_pid(av);
    if (my_strcmp(av[1], "-s") == 0)
        exit(0);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        print_usage();
        return (84);
    }
    if (ac == 2) {
        if (my_strcmp(av[1], "--help") == 0) {
            print_usage();
            return (84);
        }
        if (my_strcmp(av[1], "-s") == 0)
            my_putstr("strace : l'option requiert un argument\n");
        if (my_strcmp(av[1], "-p") == 0)
            my_putstr("strace : l'option requiert un argument\n");
        return (84);
    }
    if (ac == 3)
        option(ac, av);
    else if (ac != 1)
        launch_progname(av);
}
