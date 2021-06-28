/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define _GNU_SOURCE

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <ar.h>

#if defined(__LP64__)
#define ElfW(type) Elf64_ ## type
#else
#define ElfW(type) Elf32_ ## type
#endif

typedef struct s_symbols {
    unsigned int value;
    char type;
    char *name;
    int print_value;
}t_symbols;

typedef struct s_symb {
    char c;
    int flag;
    int type;
}t_symb;


void nm32(char *data, char *file_name, Elf32_Ehdr *elf);
void print_error(void);
char *check_error(char *file_name);
void print_symbol(t_symbols *sym, int size);
void pushswap(t_symbols *sym, int size);
char get64type(Elf64_Ehdr *elf, Elf64_Shdr *section, Elf64_Sym *sym);
char get32type(Elf32_Ehdr *elf, Elf32_Shdr *section, Elf32_Sym *sym);
void asigne_sym(t_symbols *sym, Elf32_Ehdr *elf,
                Elf32_Shdr *section, Elf32_Sym *symbol);
void asigne_sym64(t_symbols *sym, Elf64_Ehdr *elf,
                  Elf64_Shdr *section, Elf64_Sym *symbol);
void atribu(char *data, struct ar_hdr **ar_h, char **buf_name);
#endif /* !MY_H_ */
