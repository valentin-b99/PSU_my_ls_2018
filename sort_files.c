/*
** EPITECH PROJECT, 2019
** sort_files
** File description:
** sort_files
*/

#include "include/my_ls.h"

int test_rev(all_t *all)
{
    if (all->flags[3])
        return (1);
    else
        return (-1);
}

void alpha_sort_files(all_t *all, list_dir_t *list)
{
    elem_dir_t *elem = list->first;
    elem_dir_t *prev_elem = list->first;

    while (elem && elem->next) {
        if (my_strcmp_lc(elem->name, elem->next->name) == test_rev(all)) {
            if (prev_elem != elem)
                swap_elem(prev_elem, elem, elem->next, elem->next->next);
            else
                swap_first_elem(list, elem, elem->next, elem->next->next);
            elem = list->first;
            prev_elem = list->first;
        } else {
            prev_elem = elem;
            elem = elem->next;
        }
    }
}

void time_sort_files(all_t *all, list_dir_t *list)
{
    elem_dir_t *elem = list->first;
    elem_dir_t *prev_elem = list->first;

    while (elem && elem->next) {
        if ((!all->flags[3] && elem->last_modif < elem->next->last_modif) ||
            (all->flags[3] && elem->last_modif > elem->next->last_modif)) {
            if (prev_elem != elem)
                swap_elem(prev_elem, elem, elem->next, elem->next->next);
            else
                swap_first_elem(list, elem, elem->next, elem->next->next);
            elem = list->first;
            prev_elem = list->first;
        } else {
            prev_elem = elem;
            elem = elem->next;
        }
    }
}

void sort_files(all_t *all, list_dir_t *list)
{
    if (all->flags[4])
        time_sort_files(all, list);
    else
        alpha_sort_files(all, list);
}