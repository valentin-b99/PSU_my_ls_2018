/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include "../../include/my.h"
#include <stdlib.h>

void my_memset(char *str, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = 0;
}

int return_and_free(int exit, char *c_s1, char *c_s2)
{
    free(c_s1);
    free(c_s2);
    return (exit);
}

int my_strcmp_lc(char const *s1, char const *s2)
{
    int i = 0;
    char *c_s1 = malloc(sizeof(char) * my_strlen(s1));
    char *c_s2 = malloc(sizeof(char) * my_strlen(s2));

    my_memset(c_s1, my_strlen(s1));
    my_memset(c_s2, my_strlen(s2));
    c_s1 = my_strcpy(c_s1, s1);
    c_s2 = my_strcpy(c_s2, s2);
    c_s1 = my_strlowcase(c_s1);
    c_s2 = my_strlowcase(c_s2);
    while (c_s1[i] == c_s2[i] && c_s1[i] != 0 && c_s2[i] != 0)
        i++;
    if (c_s1[i] > c_s2[i])
        return (return_and_free(-1, c_s1, c_s2));
    else if (c_s1[i] < c_s2[i])
        return (return_and_free(1, c_s1, c_s2));
    else
        return (return_and_free(0, c_s1, c_s2));
}