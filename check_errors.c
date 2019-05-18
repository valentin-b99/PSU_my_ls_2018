/*
** EPITECH PROJECT, 2019
** chech_errors
** File description:
** check_errors
*/

#include "include/my_ls.h"

int check_errors(all_t *all, char *path, struct stat *st, DIR *file)
{
    if (errno == 20) {
        stat(path, st);
        add_elem_file(path, &all->files, st);
        return (1);
    }
    if (file == NULL) {
        my_putstr("Error: cannot access '");
        my_putstr(path);
        my_putstr("': No such file or directory\n");
        return (1);
    }
    return (0);
}