/*
** EPITECH PROJECT, 2021
** outil
** File description:
** outil
*/

#include "my.h"

void print_error(void)
{
    fprintf(stderr, "my_nm: 'a.out': No such file\n");
}

char *check_error(char *file_name)
{
    struct stat st;
    int fd = open(file_name, O_RDONLY);
    char *result;

    if (fd == -1 || stat(file_name, &st) != 0) {
        print_error();
        return (NULL);
    }
    if (S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s: Warning: '%s' is not an ordinary file\n",
                program_invocation_short_name, file_name);
        return (NULL);
    }
    result = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close (fd);
    return (result);
}

char *delcaract(char *name, int size)
{
    char *str = malloc(sizeof(char) * size);
    int k = 0;

    for (int i = 0; name[i]; i++) {
        if (name[i] == '_' || name[i] == '.') {
            k++;
            continue;
        } else
            str[i - k] = name[i];
    }
    return (str);
}

void print_symbol(t_symbols *sym, int size)
{
    for (int i = 0; i < size; i++) {
        if (sym[i].print_value)
            printf("                ");
        else
            printf("%016x", sym[i].value);
        printf(" %c", sym[i].type);
        printf(" %s\n", sym[i].name);
    }
}

void pushswap(t_symbols *sym, int size)
{
    t_symbols tmp;
    char *str1;
    char *str2;

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            str1 = delcaract(sym[a].name, size);
            str2 = delcaract(sym[b].name, size);
            fflush(stdout);
            if (strcasecmp(str1, str2) < 0) {
                memcpy(&tmp, sym + a, sizeof(tmp));
                memcpy(sym + a, sym + b, sizeof(tmp));
                memcpy(sym +b, &tmp, sizeof(tmp));
            }
            free(str1);
            free(str2);
        }
    }
}
