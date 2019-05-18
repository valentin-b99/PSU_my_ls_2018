/*
** EPITECH PROJECT, 2019
** read_flags
** File description:
** read_flags
*/

#include "include/my_ls.h"
#include "include/flags.h"

void add_flag(all_t *all, char c, int k, int *no_find)
{
    if (c == list_flags[k].form) {
        all->flags[list_flags[k].id] = 1;
        *no_find = 0;
    }
}

void test_valid_flag(all_t *all, char *av)
{
    int no_find = 1;

    for (int i = 1; i < my_strlen(av); i++) {
        for (int k = 0; k < NB_FLAGS && no_find; k++)
            add_flag(all, av[i], k, &no_find);
        if (no_find) {
            my_putstr("Error: invalid option -- '");
            my_putchar(av[i]);
            my_putstr("'\n");
            exit(84);
        }
        no_find = 1;
    }
}

void read_flags(all_t *all, int ac, char **av)
{
    if (ac < 2)
        return;
    for (int i = 1; i < ac; i++)
        if (av[i][0] == PRE_FLAGS)
            test_valid_flag(all, av[i]);
}