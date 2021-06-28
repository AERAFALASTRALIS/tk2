/*
** EPITECH PROJECT, 2021
** nm32
** File description:
** nm32
*/

#include "my.h"

void asigne_sym64(t_symbols *sym, Elf64_Ehdr *elf,
                  Elf64_Shdr *section, Elf64_Sym *symbol)
{
    sym->name = (void *)elf + ((typeof(section))((void *)elf +
                (elf->e_shoff + section->sh_link *
                elf->e_shentsize)))->sh_offset + symbol->st_name;
    sym->value = symbol->st_value;
    sym->print_value = (symbol->st_shndx == SHN_UNDEF ||
                        (ELF64_ST_BIND(symbol->st_info) ==
                         STB_WEAK && !symbol->st_value &&
                         ELF64_ST_TYPE(symbol->st_info) !=
                         STT_OBJECT));
    sym->type = get64type(elf, section, symbol);
}

void asigne_sym(t_symbols *sym, Elf32_Ehdr *elf,
                Elf32_Shdr *section, Elf32_Sym *symbol)
{
    sym->name = (void *)elf + ((typeof(section))((void *)elf +
                (elf->e_shoff + section->sh_link *
                elf->e_shentsize)))->sh_offset + symbol->st_name;
    sym->value = symbol->st_value;
    sym->print_value = (symbol->st_shndx == SHN_UNDEF ||
                        (ELF32_ST_BIND(symbol->st_info) ==
                         STB_WEAK && !symbol->st_value &&
                         ELF32_ST_TYPE(symbol->st_info) !=
                         STT_OBJECT));
    sym->type = get32type(elf, section, symbol);
}

void parse_32(Elf32_Shdr *section, Elf32_Ehdr *elf, char *data)
{
    Elf32_Sym *symbol = (void *)data + section->sh_offset;
    t_symbols *sym = malloc(sizeof(t_symbols) *
                            (section->sh_size / sizeof(Elf32_Sym)));
    int i;
    int k = 0;

    for (i = 1; (char *)(symbol + i) < data + section->sh_offset +
             section->sh_size; i++) {
        if (ELF32_ST_TYPE(symbol[i].st_info) != STT_FILE &&
            ELF32_ST_TYPE(symbol[i].st_info) != STT_SECTION) {
            asigne_sym(sym + k, elf, section, symbol + i);
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
