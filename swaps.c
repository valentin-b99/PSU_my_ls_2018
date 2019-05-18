/*
** EPITECH PROJECT, 2019
** swaps
** File description:
** swaps
*/

#include "include/my_ls.h"

void swap_elem(elem_dir_t *prev, elem_dir_t *elem_1, elem_dir_t *elem_2,
elem_dir_t *next)
{
    prev->next = elem_2;
    if (next)
        elem_1->next = next;
    else
        elem_1->next = NULL;
    elem_2->next = elem_1;
}

void swap_first_elem(list_dir_t *list, elem_dir_t *elem_1, elem_dir_t *elem_2,
elem_dir_t *next)
{
    list->first = elem_2;
    elem_1->next = next;
    elem_2->next = elem_1;
}