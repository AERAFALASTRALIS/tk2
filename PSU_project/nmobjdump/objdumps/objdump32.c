/*
** EPITECH PROJECT, 2021
** objdump32
** File description:
** objdump32
*/

#include "flags.h"
#include "mybis.h"

extern char const *g_flags[];

int get_flag32(char *data, Elf32_Ehdr *elf)
{
    Elf32_Shdr *section;
    int flags = 0;

    for (int i = 0; i < elf->e_shnum; i++) {
        section = (void *)data + (elf->e_shoff + elf->e_shentsize * i);
        flags |=
            HAS_RELOC * (elf->e_type == ET_REL &&
                         (section->sh_type == SHT_RELA ||
                          section->sh_type == SHT_REL)) |
            EXEC_P * (elf->e_type == ET_EXEC) |
            HAS_SYMS * (section->sh_type == SHT_SYMTAB ||
                        section->sh_type == SHT_DYNSYM) |
            DYNAMIC * (elf->e_type == ET_DYN) |
            D_PAGED * (elf->e_type == ET_EXEC ||
                       elf->e_type == ET_DYN);
    }
    return (flags);
}

void print_header32(char *data, char *file_name,  Elf32_Ehdr *elf)
{
    char *buf = strdup("");
    int flag = get_flag32(data, elf);

    for (int i = 0; i < 11; i++)
        if (flag >> i & 1) {
            asprintf(&buf, "%s%s", buf, g_flags[i + 1]);
            buf[MAX(strlen(buf), 2) - 2] = 0;
        }
    printf("\n%s:     file format elf32-i386\narchitecture: %s, flags"
           " 0x%08x:\n%s\nstart address 0x%08lx\n\n", file_name,
           elf->e_machine == EM_386 ? "i386" :"Unknown",
           flag, buf, elf->e_entry);
    free(buf);
}

void objdump32(char *data, char *file_name, Elf32_Ehdr *elf)
{
    Elf32_Shdr *s;
    char *cmp;

    print_header32(data, file_name, elf);
    s = (void *)data + (elf->e_shstrndx *elf->e_shentsize+elf->e_shoff);
    cmp = data + s->sh_offset;
    for (int i = 0; i < elf->e_shnum; i++) {
        s = (void *)data + (elf->e_shoff + i * elf->e_shentsize);
        if (s->sh_size && s->sh_type != SHT_NOBITS &&
            s->sh_type != SHT_SYMTAB &&
            (s->sh_type != SHT_STRTAB ||
             !strcmp(cmp + s->sh_name, ".dynstr")) &&
            ((s->sh_flags & SHF_ALLOC) ||
             (s->sh_type != SHT_RELA && s->sh_type != SHT_REL)))
            print_s(data + s->sh_offset, s->sh_size,
                    s->sh_addr, cmp + s->sh_name);
    }
}
