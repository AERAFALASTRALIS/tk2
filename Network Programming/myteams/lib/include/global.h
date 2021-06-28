/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** global.h
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int testnbr(char *str);
int my_getnbr(char const *str);

#endif /* !GLOBAL_H_ */
