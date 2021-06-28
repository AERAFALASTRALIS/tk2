/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** start_server
*/

#include "../../lib/include/global.h"
#include "../../lib/include/server.h"

int start_server(char **argv)
{
    int port = my_getnbr(argv[1]);
    extern int make_socket (uint16_t port);
    fd_set active_fd_set, read_fd_set;
    int i;
    struct sockaddr_in clientname;
    size_t size;
    int sock = make_socket(port);
    if (listen(sock, 1) < 0) {
        perror("listee");
        exit (EXIT_FAILURE);
    }
    FD_ZERO (&active_fd_set);
    FD_SET (sock, &active_fd_set);
    while (1) {
        read_fd_set = active_fd_set;
        if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0) {
            perror ("select");
            exit (EXIT_FAILURE);
        }
        for (i = 0; i < FD_SETSIZE; i++)
            if (FD_ISSET (i, &read_fd_set)) {
                if (i == sock) {
                    int new;
                    size = sizeof(clientname);
                    new = accept(sock,
                                (struct sockaddr *) &clientname, &size);
                    if (new < 0) {
                        perror ("accept");
                        exit (EXIT_FAILURE);
                    }
                    fprintf(stderr, "server: connect from host %s, port %hd.\n",
                            inet_ntoa (clientname.sin_addr),
                            ntohs (clientname.sin_port));
                    FD_SET (new, &active_fd_set);
                } else {
                    if (read_from_client (i) < 0) {
                        close (i);
                        FD_CLR (i, &active_fd_set);
                    }
                }
            }
    };
}

int read_from_client (int filedes) {
    char buffer[MAXMSG];
    int nbytes = read (filedes, buffer, MAXMSG);
    
    if (nbytes < 0) {
        perror ("read");
        exit (EXIT_FAILURE);
    } else if (nbytes == 0)
        return -1;
    else {
        fprintf(stderr, "server: got message: `%s'\n", buffer);
        return 0;
    }
}

int make_socket (uint16_t port) {
    int sock;
    struct sockaddr_in name;
    sock = socket( PF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        perror ("socket");
        exit (EXIT_FAILURE);
    }
    name.sin_family = AF_INET;
    name.sin_port = htons (port);
    name.sin_addr.s_addr = htonl (INADDR_ANY);
    if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0) {
        perror ("bind");
        exit (EXIT_FAILURE);
    }
    return sock;
}
