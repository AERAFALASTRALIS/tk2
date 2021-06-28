/*
** EPITECH PROJECT, 2021
** type32
** File description:
** type32
*/

#include "my.h"

extern t_symb symb[];

char check_weak32(char c, Elf32_Sym *sym)
{
    char weak = c;

    if (ELF32_ST_BIND(sym->st_info) == STB_WEAK)
        weak = 'W';
    else if (ELF32_ST_BIND(sym->st_info) == STB_WEAK
             && ELF32_ST_TYPE(sym->st_info) == STT_OBJECT)
        weak = 'V';
    if ((ELF32_ST_BIND(sym->st_info) == STB_LOCAL && weak != '?')
        || ((weak == 'W' || weak == 'V') && c == 'U'))
        weak = weak + 32;
    return (weak);
}

char check_stt32(Elf32_Shdr *shdr, Elf32_Sym *sym)
{
    if ((ELF32_ST_TYPE(sym->st_info) == STT_OBJECT &&
         shdr[sym->st_shndx].sh_flags == (SHF_WRITE | SHF_ALLOC))
        || (ELF32_ST_TYPE(sym->st_info) == STT_NOTYPE &&
            shdr[sym->st_shndx].sh_flags == (SHF_WRITE | SHF_ALLOC)))
        return ('T');
    else
        return ('?');
}

char get32type(Elf32_Ehdr *elf, Elf32_Shdr *section, Elf32_Sym *sym)
{
    int i;
    char c;

    if (sym->st_shndx == SHN_COMMON)
        return ('C');
    else if (sym->st_shndx == SHN_ABS)
        return ('A');
    i = 0;
    c = -1;
    while (symb[i].c != 0 && c == -1) {
        if (section[sym->st_shndx].sh_type == symb[i].type
            && section[sym->st_shndx].sh_flags == symb[i].flag)
            c = symb[i].c;
        i = i + 1;
    }
    if (c == -1)
        c = check_stt32(section, sym);
    c = check_weak32(c, sym);
    return (c);
}

void atribu(char *data, struct ar_hdr **ar_h, char **buf_name)
{
    *ar_h = (void *)data + SARMAG;
    *ar_h = (void *)*ar_h + atoi((*ar_h)->ar_size) + sizeof(**ar_h);
    *buf_name = (void *)*ar_h + sizeof(**ar_h);
    *ar_h = (void *)*ar_h + atoi((*ar_h)->ar_size) + sizeof(**ar_h);
}
