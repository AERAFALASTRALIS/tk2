/*
** EPITECH PROJECT, 2021
** nm
** File description:
** nm
*/

#include "my.h"

void parse_64(Elf64_Shdr *section, Elf64_Ehdr *elf, char *data)
{
    Elf64_Sym *symbol = (void *)data + section->sh_offset;
    t_symbols *sym = malloc(sizeof(t_symbols) *
                     (section->sh_size / sizeof(Elf64_Sym)));
    int i;
    int k = 0;

    for (i = 1; (char *)(symbol + i) < data + section->sh_offset +
             section->sh_size; i++) {
        if (ELF64_ST_TYPE(symbol[i].st_info) != STT_FILE &&
            ELF64_ST_TYPE(symbol[i].st_info) != STT_SECTION) {
            asigne_sym64(sym + k, elf, section, symbol + i);
            k++;
        }
    }
    pushswap(sym, k);
    print_symbol(sym, k);
}

void nm64(char *data, char *file_name, Elf64_Ehdr *elf)
{
    Elf64_Shdr *sectio;

    for (int i = 0; i < elf->e_shnum; i++) {
        sectio = (void *)data + (elf->e_shoff + (i * elf->e_shentsize));
        if (sectio->sh_type == SHT_SYMTAB)
            parse_64(sectio, elf, data);
    }
}

void nm(char *data, char *file_name)
{
    Elf64_Ehdr *head = (void *)data;
    if (head->e_ident[EI_MAG0] != ELFMAG0 ||
        head->e_ident[EI_MAG1] != ELFMAG1 ||
        head->e_ident[EI_MAG2] != ELFMAG2 ||
        head->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "%s: %s: File format not recognized\n",
                program_invocation_short_name, file_name);
    } else {
        if (head->e_ident[EI_CLASS] == ELFCLASS64)
            nm64(data, file_name, head);
        else if (((Elf32_Ehdr *)head)->e_ident[EI_CLASS] == ELFCLASS32)
            nm32(data, file_name, (Elf32_Ehdr *)head);
    }
}

void parse_archive(char *data, char *file_name)
{
    char *buf_name;
    char *name;
    struct ar_hdr *ar_h;
    struct stat st;
    stat(file_name, &st);
    atribu(data, &ar_h, &buf_name);
    while ((char *)ar_h - data < st.st_size) {
        if (strchr(ar_h->ar_name, '/')[1] == ' ')
            name = strndup(ar_h->ar_name,
                           strchr(ar_h->ar_name, '/') - ar_h->ar_name);
        else {
            char *tmp = buf_name + atoi(strchr(ar_h->ar_name, '/') + 1);
            name = strndup(tmp, strchr(tmp, '/') - tmp);
        }
        printf("\n%s:\n", name);
        nm((void *)ar_h + sizeof(*ar_h), name);
        free(name);
        ar_h = (void *)ar_h + atoi(ar_h->ar_size) + sizeof(*ar_h);
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
            nm(data, av[i]);
    }
    return (0);
}
