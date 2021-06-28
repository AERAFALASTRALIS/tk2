/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** server.h
*/

#ifndef SERVER_H
#define SERVER_H

#define MAXMSG 512

int help(void);
int start_server(char **argv);
int read_from_client (int filedes);
int make_socket(uint16_t port);

#endif /* !SERVER_H_ */
