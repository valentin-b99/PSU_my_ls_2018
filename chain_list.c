/*
** EPITECH PROJECT, 2019
** chain_list
** File description:
** chain_list
*/

#include "include/my_ls.h"

void init_list(list_dir_t *list)
{
    list->nb = 0;
    list->first = NULL;
}

void add_elem(char *path, list_dir_t *list, struct dirent *dr, struct stat *st)
{
    elem_dir_t *elem = malloc(sizeof(elem_dir_t));

    elem->name = malloc(sizeof(char) * my_strlen(dr->d_name));
    elem->name = my_strcpy(elem->name, dr->d_name);
    add_type(elem, dr, st);
    elem->blocks = st->st_blocks;
    add_perms(&elem->perms, st);
    elem->links = st->st_nlink;
    elem->usr_name = getpwuid(st->st_uid)->pw_name;
    elem->grp_name = getgrgid(st->st_gid)->gr_name;
    elem->size = st->st_size;
    elem->last_modif = st->st_mtime;
    add_symb_link(&elem->symb_link, path, elem->name);
    elem->next = list->first;
    list->nb += 1;
    list->first = elem;
}

void add_elem_file(char *path, list_dir_t *list, struct stat *st)
{
    elem_dir_t *elem = malloc(sizeof(elem_dir_t));

    elem->name = malloc(sizeof(char) * my_strlen(path));
    elem->name = my_strcpy(elem->name, path);
    elem->type = 8;
    elem->blocks = st->st_blocks;
    add_perms(&elem->perms, st);
    elem->links = st->st_nlink;
    elem->usr_name = getpwuid(st->st_uid)->pw_name;
    elem->grp_name = getgrgid(st->st_gid)->gr_name;
    elem->size = st->st_size;
    elem->last_modif = st->st_mtime;
    add_symb_link(&elem->symb_link, path, elem->name);
    elem->next = list->first;
    list->nb += 1;
    list->first = elem;
}