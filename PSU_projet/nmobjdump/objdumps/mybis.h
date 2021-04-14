/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MYBIS_H_
#define MYBIS_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#if defined(__LP64__)
#define ElfW(type) Elf64_ ## type
#else
#define ElfW(type) Elf32_ ## type
#endif 

#endif /* !MYBIS_H */
