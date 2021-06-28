/*
** EPITECH PROJECT, 2021
** type
** File description:
** type
*/

#include "my.h"

t_symb symb[] = {
    {'U', SHT_NULL, 0},
    {'N', SHT_PROGBITS, 0},
    {'R', SHT_PROGBITS, SHF_ALLOC},
    {'T', SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR},
    {'D', SHT_PROGBITS, SHF_ALLOC | SHF_WRITE},
    {'B', SHT_NOBITS, SHF_ALLOC | SHF_WRITE},
    {'D', SHT_DYNAMIC, SHF_ALLOC | SHF_WRITE},
    {0, 0, 0}
};

char check_weak(char c, Elf64_Sym *sym)
{
    char weak = c;

    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK)
        weak = 'W';
    else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK
             && ELF64_ST_TYPE(sym->st_info) == STT_OBJECT)
        weak = 'V';
    if ((ELF64_ST_BIND(sym->st_info) == STB_LOCAL && weak != '?')
        || ((weak == 'W' || weak == 'V') && c == 'U'))
        weak = weak + 32;
    return (weak);
}

char check_stt(Elf64_Shdr *shdr, Elf64_Sym *sym)
{
    if ((ELF64_ST_TYPE(sym->st_info) == STT_OBJECT &&
         shdr[sym->st_shndx].sh_flags == (SHF_WRITE | SHF_ALLOC))
        || (ELF64_ST_TYPE(sym->st_info) == STT_NOTYPE &&
            shdr[sym->st_shndx].sh_flags == (SHF_WRITE | SHF_ALLOC)))
        return ('T');
    else
        return ('?');
}

char get64type(Elf64_Ehdr *elf, Elf64_Shdr *section, Elf64_Sym *sym)
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
        c = check_stt(section, sym);
    c = check_weak(c, sym);
    return (c);
}
