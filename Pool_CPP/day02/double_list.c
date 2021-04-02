/*
** EPITECH PROJECT, 2021
** double
** File description:
** double
*/

#include "double_list.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int i = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return (i);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    while (list != '\0')
    {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    t_list nw_elem;

    nw_elem = malloc(sizeof(t_list));
    if (nw_elem == NULL)
        return (false);
    nw_elem->value = elem;
    nw_elem->next = *front_ptr;
    *front_ptr = nw_elem;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    t_list lst_elem;
    t_list nw_elem;

    lst_elem = malloc(sizeof(t_list));
    if (lst_elem == NULL)
        return (false);
    lst_elem->next = NULL;
    lst_elem->value = elem;
    if (*front_ptr == NULL)
        return (list_add_elem_at_front(front_ptr, elem));
    nw_elem = *front_ptr;
    while (nw_elem->next != NULL)
        nw_elem = new_elem->next;
    nw_elem->next = lst_elem;
    return (true);
}
