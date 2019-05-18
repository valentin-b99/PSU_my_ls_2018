/*
** EPITECH PROJECT, 2019
** my_strnncpy
** File description:
** my_strnncmpy
*/

#include <stdlib.h>

char *my_strnncpy(char *src, int start, int end)
{
    char *result = malloc(sizeof(char) * (end - start + 1));
    int i = 0;
    int j = 0;

    while (src[i]) {
        if (i >= start && i <= end) {
            result[j] = src[i];
            j++;
        }
        i++;
    }
    result[j] = 0;
    return (result);
}