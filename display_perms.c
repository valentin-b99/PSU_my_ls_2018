/*
** EPITECH PROJECT, 2019
** display_perms
** File description:
** display_perms
*/

#include "include/my_ls.h"

void display_usrperms(elem_dir_t *elem)
{
    if (elem->perms.user.r)
        my_putstr("r");
    else
        my_putstr("-");
    if (elem->perms.user.w)
        my_putstr("w");
    else
        my_putstr("-");
    if (elem->perms.user.x)
        my_putstr("x");
    else
        my_putstr("-");
}

void display_grpperms(elem_dir_t *elem)
{
    if (elem->perms.group.r)
        my_putstr("r");
    else
        my_putstr("-");
    if (elem->perms.group.w)
        my_putstr("w");
    else
        my_putstr("-");
    if (elem->perms.group.x)
        my_putstr("x");
    else
        my_putstr("-");
}

void display_otrperms(elem_dir_t *elem)
{
    if (elem->perms.other.r)
        my_putstr("r");
    else
        my_putstr("-");
    if (elem->perms.other.w)
        my_putstr("w");
    else
        my_putstr("-");
    if (elem->perms.other.x == 512)
        my_putstr("T. ");
    else if (elem->perms.other.x)
        my_putstr("x. ");
    else
        my_putstr("-. ");
}