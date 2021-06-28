/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MYBIS_H_
#define MYBIS_H_

#define _GNU_SOURCE

#define MIN(x, y) (y ^ ((x ^ y) & -(x < y)))
#define MAX(x, y) (x ^ ((x ^ y) & -(x < y)))

#include <errno.h>
#include <ctype.h>
#include <math.h>
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

void parse_archive(char *data, char *file_name);
void objdump(char *data, char *file_name);
int get_flag32(char *data, Elf32_Ehdr *elf);
void print_header32(char *data, char *file_name,  Elf32_Ehdr *elf);
void objdump32(char *data, char *file_name, Elf32_Ehdr *elf);
void print_error(char *src);
char *check_error(char *file_name);
void print_s(char *section, size_t size, size_t line, char *);

#endif /* !MYBIS_H */
