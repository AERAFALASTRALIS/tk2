/*
** EPITECH PROJECT, 2021
** coursce
** File description:
** coursce
*/

#include "../include/server.h"

static t_ptr g_cmd[10] =
{
    {"CWD", cwd},
    {"CDUP", cdup},
    {"HELP", help},
    {"noop", noop},
    {"PWD", pwd},
    {"QUIT", quit},
    {"PASV", pasv},
    {"PORT", port},
    {"LIST", list},
    {NULL}
};

char *clear_ret(char *cmd)
{
    char *new = malloc(sizeof(char) * (strlen(cmd) + 1));
    int i;

    if (new == NULL)
        return (NULL);
    for (i = 0; cmd[i] != 0 && cmd[i] != '\r'; i++)
        new[i] = cmd[i];
    new[i] = 0;
    return (new);
}

int run(t_data *data)
{
    size_t size = 1024;
    char *cmd = malloc(sizeof(char) * size);
    char **tab;

    message(220, "Hello newcomer.", data);
    if (cmd == NULL)
        return (84);
    cmd = get_next_line(data->c_fd);
    while (1) {
        tab = my_str_to_wordtab(clear_ret(cmd), ' ');
        if (tab == NULL || tab[0] == NULL)
            return (84);
        else if (strcmp(cmd, "") != 0 && loop(data, tab) == 84)
            return (84);
        cmd = get_next_line(data->c_fd);
    }
    return (0);
}

int loop(t_data *data, char **tab)
{
    for (int i = 0; g_cmd[i].str; i++) {
        if (strcasecmp(tab[0], g_cmd[i].str) == 0) {
            if (g_cmd[i].fnc(tab, data) == 84)
                return (84);
            return (0);
        }
    }
    if (data->log == true)
        message(500, E_CMD, data);
    else
        message(530, E_LOGIN, data);
    return (0);
}

int help(char **tab, t_data *data)
{
    message(-1, I_CMD, data);
    for (int i = 0; g_cmd[i].str != NULL; i++) {
        message(-1, g_cmd[i].str, data);
        message(-1, " ", data);
    }
    message(-2, "", data);
}
