/*
** EPITECH PROJECT, 2021
** ls
** File description:
** ls
*/

#include "../include/server.h"

int cwd(char **tab, t_data *data)
{
    if (data->log == true) {
        if (tab[1] != NULL) {
            if ((chdir(tab[1])) != -1)
                message(250, I_DIR, data);
            else
                message(550, E_DIR, data);
        } else
            message(550, E_DIR, data);
    } else
        message(530, E_LOGIN, data);
    return (0);
}

int cdup(char **tab, t_data *data)
{
    if (data->log == true) {
        if (chdir("..") != -1)
            message(250, I_DIR, data);
        else
            message(550, E_DIR, data);
    } else
        message(530, E_LOGIN, data);
    return (0);
}

char *get_dir(void)
{
    char *dir = getcwd((char *)NULL, 0);
    char *new;
    int i = 1;

    if (dir == NULL)
        return (NULL);
    new = malloc(sizeof(char) * (strlen(dir) + 3));
    new[0] = 34;
    for (i = 1; dir[i - 1]; i++) {
        new[i] = dir[i - 1];
    }
    new[i] = 34;
    new[i + 1] = 0;
    return (new);
}

int pwd(char **tab, t_data *data)
{
    char *dir;

    if (data->log == true) {
        dir = get_dir();
        if (dir == NULL)
            return (84);
        message(257, dir, data);
    } else
        message(530, E_LOGIN, data);
    return (0);
}
