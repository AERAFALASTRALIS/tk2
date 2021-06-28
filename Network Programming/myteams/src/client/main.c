/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** client_main
*/

#include "../../lib/include/global.h"
#include "../../lib/include/client.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (strcmp(argv[1], "-help") == 0) {
            help();
        } else
            my_putstr("Missing parameter see -help\n");
    } else if (argc == 3) {
        checknbr(argv);
    } else
        my_putstr("Missing parameter see -help\n");
    return 0;
}

int checknbr(char **argv)
{
    if (testnbr(argv[2]) == 0) {
        my_putstr("Invalid port number\n");
        return 84;
    }
    start_client(argv);
}

int help(void)
{
    my_putstr("USAGE: ./myteams_cli ip port\n     ip     is the serve");
    my_putstr("r ip address on which the server socket listens\n     ");
    my_putstr("port   is the port number on which the servre socket ");
    my_putstr("listens\n");
    return 0;
}
