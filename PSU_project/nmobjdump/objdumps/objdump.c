/*
** EPITECH PROJECT, 2021
** objdump
** File description:
** objdump
*/

#include "mybis.h"
#include "flags.h"

char const *g_flags[] = {
    "BFD_NO_FLAGS, ",
    "HAS_RELOC, ",
    "EXEC_P, ",
    "HAS_LINENO, ",
    "HAS_DEBUG, ",
    "HAS_SYMS, ",
    "HAS_LOCALS, ",
    "DYNAMIC, ",
    "WP_TEXT, ",
    "D_PAGED, ",
};

int get_flag64(char *data, Elf64_Ehdr *elf)
{
    Elf64_Shdr *section;
    int flags = 0;

    for (int i = 0; i < elf->e_shnum; i++) {
        section = (void *)data + (elf->e_shoff + elf->e_shentsize * i);
        flags |= HAS_RELOC * (elf->e_type == ET_REL &&
                              (section->sh_type == SHT_RELA ||
                               section->sh_type == SHT_REL)) |
            EXEC_P * (elf->e_type == ET_EXEC) |
            HAS_SYMS * (section->sh_type == SHT_SYMTAB ||
                        section->sh_type == SHT_DYNSYM) |
            DYNAMIC * (elf->e_type == ET_DYN) |
            D_PAGED * (elf->e_type == ET_EXEC || elf->e_type == ET_DYN);
    }
    return (flags);
}

void print_header(char *data, char *file_name,  Elf64_Ehdr *elf)
{
    char *buf = strdup("");
    int flag = get_flag64(data, elf);

    for (int i = 0; i < 11; i++)
        if (flag >> i & 1) {
            asprintf(&buf, "%s%s", buf, g_flags[i + 1]);
            buf[MAX(strlen(buf), 2) - 2] = 0;
        }
    printf("\n%s:     file format elf64-x86-64\narchitecture: %s, flags"
           " 0x%08x:\n%s\nstart address 0x%016lx\n\n", file_name,
           elf->e_machine == EM_X86_64 ? "i386:x86_64" :"Unknown",
           flag, buf, elf->e_entry);
    free(buf);
}

void objdump64(char *data, char *file_name, Elf64_Ehdr *elf)
{
    Elf64_Shdr *s;
    char *cmp;

    print_header(data, file_name, elf);
    s = (void *)data + (elf->e_shstrndx *elf->e_shentsize+elf->e_shoff);
    cmp = data + s->sh_offset;
    for (int i = 0; i < elf->e_shnum; i++) {
        s = (void *)data + (elf->e_shoff + i * elf->e_shentsize);
        if (s->sh_size && s->sh_type != SHT_NOBITS &&
            s->sh_type != SHT_SYMTAB && (s->sh_type != SHT_STRTAB ||
            !strcmp(cmp + s->sh_name, ".dynstr")) &&
            ((s->sh_flags & SHF_ALLOC) || (s->sh_type != SHT_RELA &&
                                           s->sh_type != SHT_REL)))
            print_s(data + s->sh_offset, s->sh_size, s->sh_addr,
                    cmp + s->sh_name);
    }
}

void objdump(char *data, char *file_name)
{
    Elf64_Ehdr *header = (void *)data;
    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
        header->e_ident[EI_MAG1] != ELFMAG1 ||
        header->e_ident[EI_MAG2] != ELFMAG2 ||
        header->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s: %s: File format not recognized\n",
                program_invocation_short_name, file_name);
    } else {
        if (header->e_ident[EI_CLASS] == ELFCLASS64)
            objdump64(data, file_name, header);
        else if (((Elf32_Ehdr *)header)->e_ident[EI_CLASS] == ELFCLASS32)
            objdump32(data, file_name, (Elf32_Ehdr *)header);
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (84);
    char *data;

    for (int i = 1; i < ac; i++) {
        data = check_error(av[i]);
        if (data == NULL)
            continue;
        if (data == MAP_FAILED) {
            perror(av[i]);
            continue;
        }
        if (strlen(data) > SARMAG && !strncmp(ARMAG, data, SARMAG))
            parse_archive(data, av[i]);
        else
            objdump(data, av[i]);
    }
    return (0);
}
