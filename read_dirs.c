/*
** EPITECH PROJECT, 2019
** read_dirs
** File description:
** read_dirs
*/

#include "include/my_ls.h"

void display_path(all_t *all, char *path)
{
    if ((all->nb_dir > 1 || all->flags[1]) && !all->flags[2]) {
        my_putstr(path);
        my_putstr(":\n");
    }
}

int read_dirs(all_t *all, char *path, list_dir_t *list)
{
    DIR *file = opendir(path);
    struct dirent *dr;
    struct stat st;

    if (check_errors(all, path, &st, file))
        return (0);
    display_path(all, path);
    while (dr = readdir(file)) {
        stat(my_strcat(my_strcat(path, "/"), dr->d_name), &st);
        add_elem(path, list, dr, &st);
    }
    closedir(file);
    return (1);
}

void display_recursive(all_t *all, list_dir_t *list, char *path)
{
    list_dir_t *r_files = malloc(sizeof(list_dir_t));
    elem_dir_t *elem = list->first;

    init_list(r_files);
    my_putstr("\n");
    while (elem) {
        if (elem->name[0] != '.' && elem->type == 4) {
            if (read_dirs(all, my_strcat(my_strcat(path, "/"), elem->name),
                r_files)) {
                sort_files(all, r_files);
                display_files(all, r_files, "");
                display_recursive(all, r_files, my_strcat(my_strcat(path, "/"),
                elem->name));
            }
        }
        elem = elem->next;
    }
    free_list(r_files);
}

void display_line_return(all_t *all)
{
    if (!all->flags[2])
        my_putstr("\n");
}

void read_all_dir(all_t *all, int ac, char **av)
{
    int nb_list = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != PRE_FLAGS) {
            nb_list++;
            if (!read_dirs(all, av[i], &all->files))
                all->error = 1;
            sort_files(all, &all->files);
            display_files(all, &all->files, av[i]);
            if (all->flags[1])
                display_recursive(all, &all->files, av[i]);
            free_list(&all->files);
            if (nb_list < all->nb_dir) {
                display_line_return(all);
                init_list(&all->files);
            }
        }
    }
}