/*
** EPITECH PROJECT, 2019
** displays
** File description:
** displays
*/

#include "include/my_ls.h"

void display_total(list_dir_t *list)
{
    elem_dir_t *elem = list->first;
    unsigned int total = 0;

    while (elem) {
        if (elem->name[0] != '.')
            total += elem->blocks;
        elem = elem->next;
    }
    my_putstr("total ");
    my_putnbr(total / 2);
    my_putstr("\n");
}

void display_type(elem_dir_t *elem)
{
    if (elem->type == 4)
        my_putstr("d");
    if (elem->type == 10)
        my_putstr("l");
    if (elem->type == 4096)
        my_putstr("b");
    if (elem->type == 4242)
        my_putstr("c");
    if (elem->type == 2 || elem->type == 8)
        my_putstr("-");
}

void display_fl(elem_dir_t *elem)
{
    display_type(elem);
    display_usrperms(elem);
    display_grpperms(elem);
    display_otrperms(elem);
    my_putnbr(elem->links);
    my_putstr(" ");
    my_putstr(elem->usr_name);
    my_putstr(" ");
    my_putstr(elem->grp_name);
    my_putstr(" ");
    my_putnbr(elem->size);
    my_putstr(" ");
    my_putstr(my_strnncpy(ctime(&elem->last_modif), 4, 15));
    my_putstr(" ");
}

void display_files(all_t *all, list_dir_t *list, char *name)
{
    elem_dir_t *elem = list->first;

    if (all->flags[0] && !all->flags[2])
        display_total(list);
    while (elem) {
        if ((!all->flags[2] && elem->name[0] != '.') ||
            (all->flags[2] && !my_strcmp(elem->name, "."))) {
            if (all->flags[0])
                display_fl(elem);
            if (all->flags[2])
                my_putstr(name);
            else
                my_putstr(elem->name);
            my_putstr("\n");
        }
        elem = elem->next;
    }
    free(elem);
}