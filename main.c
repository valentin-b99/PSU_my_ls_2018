/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/my_ls.h"

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));

    init_all_struct(all, ac, av);
    if (!all->nb_dir) {
        if (!read_dirs(all, ".", &all->files))
            all->error = 1;
        sort_files(all, &all->files);
        display_files(all, &all->files, ".");
        if (all->flags[1])
            display_recursive(all, &all->files, ".");
        free_list(&all->files);
    } else {
        read_all_dir(all, ac, av);
    }
    if (all->error) {
        free(all);
        return (84);
    }
    free(all);
    return (0);
}