/*
** EPITECH PROJECT, 2019
** chain_elems
** File description:
** chain_elems
*/

#include "include/my_ls.h"

void add_perms(all_perms_t *perms, struct stat *st)
{
    perms->user.r = st->st_mode & S_IRUSR;
    perms->user.w = st->st_mode & S_IWUSR;
    perms->user.x = st->st_mode & S_IXUSR;
    perms->group.r = st->st_mode & S_IRGRP;
    perms->group.w = st->st_mode & S_IWGRP;
    perms->group.x = st->st_mode & S_IXGRP;
    perms->other.r = st->st_mode & S_IROTH;
    perms->other.w = st->st_mode & S_IWOTH;
    perms->other.x = st->st_mode & S_ISVTX;
    if (!perms->other.x)
        perms->other.x = st->st_mode & S_IXOTH;
}

void add_symb_link(char **symb_link, char *path, char *name)
{
    char buff[100];
    int count = readlink(my_strcat(path, name), buff, sizeof(buff));

    if (count >= 0)
        buff[count] = 0;
    else
        buff[0] = 0;
    *symb_link = buff;
}

void add_type(elem_dir_t *elem, struct dirent *dr, struct stat *st)
{
    if ((st->st_mode & S_IFBLK) == 24576)
        elem->type = 4096;
    else if ((st->st_mode & S_IFCHR) == 8192)
        elem->type = 4242;
    else
        elem->type = dr->d_type;
}