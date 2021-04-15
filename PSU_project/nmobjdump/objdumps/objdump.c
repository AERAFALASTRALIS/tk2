/*
** EPITECH PROJECT, 2021
** objdump
** File description:
** objdump
*/

#include "mybis.h"

void print_error(char *src, char *str)
{
    fprintf(stderr, "my_objdump: 'a.out'%s", src);
}

void print_err(char *src, char *str)
{
    fprintf(stderr, "my_objdump: %s%s",str, src);
}

int file_type(int fd)
{
    void *buf;
    Elf64_Shdr *shdr;
    unsigned char *shstrtab;
    Elf64_Ehdr *elf;
    struct stat s;
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf != (void *)-1) {
        elf = ((Elf64_Ehdr *)buf);
        shdr = ((Elf64_Shdr *)(buf + elf->e_shoff));
        shstrtab = ((unsigned char *)(buf + shdr[elf->e_shstrndx].sh_offset));
        for (int i = 0; i < elf->e_shnum; i++) {
            if (shdr[i].sh_type == SHT_SYMTAB)
                fprintf(stderr, "Symbol table found = |%d|\n", shdr[i].sh_type);
        }
        munmap(buf, s.st_size);
    } else
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    ElfW(Ehdr) header;
    if (fd != -1) {
        read(fd, &header, sizeof(header));
        if (header.e_ident[1] == 'E' && header.e_ident[2] == 'L' &&\
            header.e_ident[3] == 'F') {
            if (file_type(fd) == 84) {
                print_err(": file format not recognized\n", av[1]);
                return (84);
            }
        } else {
            print_err(": file format not recognized\n", av[1]);
            return (84);
        }
        close(fd);
    } else {
        print_error(": No such file\n", av[1]);
        return (84);
    }
    return (0);
}
