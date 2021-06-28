/*
** EPITECH PROJECT, 2021
** outils
** File description:
** outils
*/

#include "../include/server.h"

int quit(char **tab, t_data *data)
{
    printf("Client disconected IP = [%s]\n", data->ip);
    message(221, "Goodbye.", data);
    exit(0);
    return (0);
}

int check_usage(int ac, char **av)
{
    if (ac < 3 || strcmp(av[1], "-help") == 0) {
        printf("%s%s%s", USA_1, USA_2, USA_3);
        return (84);
    }
    return (0);
}

void message(int id, char *msg, t_data *data)
{
    if (id >= 0)
        dprintf(data->c_fd, "%d %s\r\n", id, msg);
    else if (id == -1)
        dprintf(data->c_fd, "%s", msg);
    else
        dprintf(data->c_fd, "\r\n");
}
