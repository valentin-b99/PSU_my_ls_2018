/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>

#define PRE_FLAGS '-'
#define NB_FLAGS 5

/**
*? chain_elems.c
*/
void add_perms(all_perms_t *, struct stat *);
void add_symb_link(char **, char *, char *);
void add_type(elem_dir_t *, struct dirent *, struct stat *);

/**
*? chain_list.c
*/
void init_list(list_dir_t *);
void add_elem(char *, list_dir_t *, struct dirent *, struct stat *);
void add_elem_file(char *, list_dir_t *, struct stat *);

/**
* ? check_errors.c
*/
int check_errors(all_t *, char *, struct stat *, DIR *);

/**
*? display_perms.c
*/
void display_usrperms(elem_dir_t *);
void display_grpperms(elem_dir_t *);
void display_otrperms(elem_dir_t *);

/**
*? display.c
*/
void display_total(list_dir_t *);
void display_type(elem_dir_t *);
void display_fl(elem_dir_t *);
void display_files(all_t *, list_dir_t *, char *);

/**
*? free.c
*/
void free_list(list_dir_t *);

/**
*? initializations.c
*/
void init_all_struct(all_t *all, int ac, char **av);

/**
*? read_files.c
*/
int read_dirs(all_t *, char *, list_dir_t *);
void read_all_dir(all_t *, int, char **);

/**
*? read_dirs.c
*/
void display_path(all_t *, char *);
int read_dirs(all_t *, char *, list_dir_t *);
void display_recursive(all_t *, list_dir_t *, char *);
void display_line_return(all_t *);
void read_all_dir(all_t *, int, char **);

/**
*? read_flags.c
*/
void add_flag(all_t *, char, int, int *);
void test_valid_flag(all_t *, char *);
void read_flags(all_t *, int, char **);

/**
*? sort_files.c
*/
int test_rev(all_t *);
void alpha_sort_files(all_t *, list_dir_t *);
void time_sort_files(all_t *, list_dir_t *);
void sort_files(all_t *, list_dir_t *);

/**
*? swaps.c
*/
void swap_elem(elem_dir_t *, elem_dir_t *, elem_dir_t *, elem_dir_t *);
void swap_first_elem(list_dir_t *, elem_dir_t *, elem_dir_t *, elem_dir_t *);

#endif /* !MY_LS_H_ */
