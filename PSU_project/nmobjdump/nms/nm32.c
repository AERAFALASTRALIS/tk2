/*
** EPITECH PROJECT, 2021
** nm32
** File description:
** nm32
*/

#include "my.h"

void asigne_sym64(t_symbols *sym, Elf64_Ehdr *elf, Elf64_Shdr *se,
Elf64_Sym *symbol)
{
    sym->name = (void *)elf + ((typeof(se))((void *)elf +
    (elf->e_shoff + se->sh_link * elf->e_shentsize)))->sh_offset +
    symbol->st_name;
    sym->value = symbol->st_value;
    sym->print_value = (symbol->st_shndx == SHN_UNDEF ||
    (ELF64_ST_BIND(symbol->st_info) == STB_WEAK && !symbol->st_value &&
    ELF64_ST_TYPE(symbol->st_info) != STT_OBJECT));
    sym->type = get64type(elf, se, symbol);
}

void asigne_sym(t_symbols *sym, Elf32_Ehdr *elf, Elf32_Shdr *se,
Elf32_Sym *symbol)
{
    sym->name = (void *)elf + ((typeof(se))((void *)elf +
        (elf->e_shoff + se->sh_link * elf->e_shentsize)))->sh_offset +
        symbol->st_name;
    sym->value = symbol->st_value;
    sym->print_value = (symbol->st_shndx == SHN_UNDEF ||
    (ELF32_ST_BIND(symbol->st_info) == STB_WEAK && !symbol->st_value &&
    ELF32_ST_TYPE(symbol->st_info) != STT_OBJECT));
    sym->type = get32type(elf, se, symbol);
}

void parse_32(Elf32_Shdr *c, Elf32_Ehdr *elf, char *d)
{
    Elf32_Sym *s = (void *)d + c->sh_offset;
    t_symbols *sym = malloc(sizeof(t_symbols) *
                            (c->sh_size / sizeof(Elf32_Sym)));
    int i;
    int k = 0;

    for (i = 1; (char *)(s + i) < d + c->sh_offset + c->sh_size; i++) {
        if (ELF32_ST_TYPE(s[i].st_info) != STT_FILE &&
            ELF32_ST_TYPE(s[i].st_info) != STT_SECTION) {
            asigne_sym(sym + k, elf, c, s + i);
            k++;
        }
    }
    pushswap(sym, k);
    print_symbol(sym, k);
}

void nm32(char *data, char *file_name, Elf32_Ehdr *elf)
{
    Elf32_Shdr *sectio;

    for (int i = 0; i < elf->e_shnum; i++) {
        sectio = (void *)data + (elf->e_shoff + (i * elf->e_shentsize));
        if (sectio->sh_type == SHT_SYMTAB)
            parse_32(sectio, elf, data);
    }
}
