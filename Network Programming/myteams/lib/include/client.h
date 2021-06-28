/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** client.h
*/

#ifndef CLIENT_H
#define CLIENT_H

int help(void);
int checknbr(char **argv);
int start_client(char **argv);
void write_to_server(int fideles);
void init_sockaddr(struct sockaddr_in *name,
                    const char *hostame,
                    uint16_t port);

#endif /* !CLIENT_H_ */
