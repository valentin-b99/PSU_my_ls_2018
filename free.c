/*
** EPITECH PROJECT, 2019
** free
** File description:
** free
*/

#include "include/my_ls.h"

void free_list(list_dir_t *list)
{
    elem_dir_t *elem = list->first;
    elem_dir_t *prev_elem = list->first;

    free(elem);
    free(prev_elem);
}