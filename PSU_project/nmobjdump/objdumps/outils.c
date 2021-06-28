/*
** EPITECH PROJECT, 2021
** outils
** File description:
** outils
*/

#include "mybis.h"

void print_error(char *src)
{
    fprintf(stderr, "my_objdump: 'a.out'%s", src);
}

char *check_error(char *file_name)
{
    struct stat st;
    int fd = open(file_name, O_RDONLY);
    char *result;

    if (fd == -1 || stat(file_name, &st) != 0) {
        print_error("Not such file");
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

void print_s(char *section, size_t s, size_t l, char *section_nam)
{
    char *buf;
    size_t m;
    printf("Contens of section %s \n", section_nam);
    for (int i = 0; s; i++) {
        m = MIN(s, 16);
        printf(" %0*lx",MAX((unsigned int)(log(s + l) / log(8)), 4), l);
        buf = section + 16 * i;
        l += 16;
        for (int k = 0; k < m; k++)
            printf("%s%02x", (k % 4) ? "" : " ", buf[k]);
        for (int k = 0; k + m * 2.25 -5 + (!(m / 4) || m % 4) < 32; k++)
            printf(" ");
        for (int k = 0; k < 16; k++)
            printf("%c",
                   k < m ? (!isprint(buf[k]) ? '.' : buf[k]) : ' ');
        printf("\n");
        s -= m;
    }
}

void atribu(char *data, struct ar_hdr **ar_h, char **buf_name)
{
    *ar_h = (void *)data + SARMAG;
    *ar_h = (void *)*ar_h + atoi((*ar_h)->ar_size) + sizeof(**ar_h);
    *buf_name = (void *)*ar_h + sizeof(**ar_h);
    *ar_h = (void *)*ar_h + atoi((*ar_h)->ar_size) + sizeof(**ar_h);
}

void parse_archive(char *data, char *file_name)
{
    char *buf_name;
    char *name;
    struct ar_hdr *ar_h;
    struct stat st;
    stat(file_name, &st);
    atribu(data, &ar_h, &buf_name);
    printf("In archive %s:\n", file_name);

    while ((char *)ar_h - data < st.st_size) {
        if (strchr(ar_h->ar_name, '/')[1] == ' ')
            name = strndup(ar_h->ar_name,
                           strchr(ar_h->ar_name, '/') - ar_h->ar_name);
        else {
            char *tmp = buf_name + atoi(strchr(ar_h->ar_name, '/') + 1);
            name = strndup(tmp, strchr(tmp, '/') - tmp);
        }
        objdump((void *)ar_h + sizeof(*ar_h), name);
        free(name);
        ar_h = (void *)ar_h + atoi(ar_h->ar_size) + sizeof(*ar_h);
    }
}
