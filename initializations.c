/*
** EPITECH PROJECT, 2019
** inititalizations
** File description:
** initializations
*/

#include "include/my_ls.h"

void init_all_struct(all_t *all, int ac, char **av)
{
    init_list(&all->files);
    all->flags = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        all->flags[i] = 0;
    read_flags(all, ac, av);
    all->nb_dir = 0;
    all->error = 0;
    for (int i = 1; i < ac; i++)
        if (av[i][0] != PRE_FLAGS)
            all->nb_dir += 1;
}