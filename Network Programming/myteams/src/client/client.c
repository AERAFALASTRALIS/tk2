/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** start_client
*/

#include "../../lib/include/global.h"
#include "../../lib/include/client.h"

int start_client(char **argv)
{
    int port = my_getnbr(argv[2]);
    extern void init_sockaddr (struct sockaddr_in *name,
    const char *hostname,
    uint16_t port);
    int sock;
    struct sockaddr_in servername;
    sock = socket (PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror ("socket (client)");
        exit (EXIT_FAILURE);
    }
    init_sockaddr(&servername, argv[1], port);
    if (0 > connect (sock, (struct sockaddr *) &servername,
                    sizeof (servername))) {
        perror ("connect (client)");
        exit (EXIT_FAILURE);
    }
    write_to_server(sock);
    close (sock);
    exit (EXIT_FAILURE);
}

void write_to_server(int fideles) 
{
    int nbytes;
    nbytes = write (fideles, "test", strlen ("test") + 1);
    if (nbytes < 0) {
        perror ("write");
        exit (EXIT_FAILURE);
    }
}

void init_sockaddr(struct sockaddr_in *name, const char *hostname,
                    uint16_t port)
{
    struct hostent *hostinfo;
    name->sin_family = AF_INET;
    name->sin_port = htons (port);
    hostinfo = gethostbyname (hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "unknown host %s.\n", hostname);
        exit (EXIT_FAILURE);
    }
    name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
}
