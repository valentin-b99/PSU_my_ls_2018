/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include <time.h>

typedef struct perm_s
{
    int r;
    int w;
    int x;
} perm_t;

typedef struct all_perms_s
{
    perm_t user;
    perm_t group;
    perm_t other;
} all_perms_t;

typedef struct elem_dir_s
{
    char *name;
    int type;
    unsigned int blocks;
    all_perms_t perms;
    unsigned int links;
    char *usr_name;
    char *grp_name;
    unsigned int size;
    time_t last_modif;
    char *symb_link;
    struct elem_dir_s *next;
} elem_dir_t;

typedef struct list_s
{
    int nb;
    struct elem_dir_s *first;
} list_dir_t;

typedef struct all_s
{
    list_dir_t files;
    int nb_dir;
    int *flags;
    int error;
} all_t;

#endif /* !STRUCT_H_ */
