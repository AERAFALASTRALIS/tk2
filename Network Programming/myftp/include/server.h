/*
** EPITECH PROJECT, 2021
** server
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdbool.h>

#define E_MALLOC "Malloc fail.\n"

#define USAGE_1 "USAGE: ./server port path\n    port is the port number"
#define USAGE_2 " on which the server socket listens\n    path is the "
#define USAGE_3 "path to the home directory for the Anonymous user\n"

#define BUFFER_SIZE 1024

#define E_PERM "Permission denied."
#define E_PASS "Login with USER first."
#define E_USER "Login with USER first."
#define E_LOGIN "Please login with USER and PASS."
#define E_BLOGIN "Login incorrect."
#define E_CMD "Unknown command."
#define E_CLOSE "Error occured while closing client fd.\n"
#define E_DIR "Failed to change directory."

#define I_PASS "Please specify the password."
#define I_DIR "Directory successfully changed."
#define I_CMD "214 The following commands are recognized : "
#define SUCCESS	0
#define ERROR 84

typedef struct s_data {
    int port;
    char *path;
    char *username;
    char *password;
    char *ip;
    int c_fd;
    int s_fd;
    bool connected;
    int pasv_fd;
} t_data;

typedef struct s_ptr {
    char *str;
    int (*fnc)();
} t_ptr;

int count_words(char *, char);
char *alloc_line(char *, char, int *);
char **my_str_to_wordtab(char *, char);
int check_usage(int, char **);
char *clear_cmd(char *);
void send_message(int, char *, t_data *);
int run(t_data *);
int cwd(char **, t_data *);
int dele(char **, t_data *);
int pwd(char **, t_data *);
t_data *init(char **);
void clear(t_data *);
int connect_to_server(t_data *, int);
int username(char **, t_data *);
int password(char **, t_data *);
int quit(char **, t_data *);
int run(t_data *);
int loop(t_data *, char **);
int help(char **, t_data *);
int list(char **, t_data *);
char *get_next_line(const int fd);
int noop(char **tab, t_data *);
int pasv(char **tab, t_data *);
int port(char **tab, t_data *);

#endif /* !SERVER_H_ */
