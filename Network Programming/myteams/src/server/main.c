/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** server_main
*/

#include "../../lib/include/global.h"
#include "../../lib/include/server.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
            if (strcmp(argv[1], "-help") == 0) {
                help();
            } else if (testnbr(argv[1]) == 0) {
                my_putstr("Invalid port number\n");
                return 84;
            }
    }
    start_server(argv);
}

int help(void)
{
    my_putstr("USAGE: ./myteams_server port\n\n     port");
    my_putstr(" is the number on which the server socket listens.\n");
    return 0;
}
