/*
** EPITECH PROJECT, 2019
** flags
** File description:
** flags
*/

#ifndef FLAGS_H_
#define FLAGS_H_

typedef struct flags_s
{
    int id;
    char form;
} flags_t;

flags_t list_flags[] =
{
    {0, 'l'},
    {1, 'R'},
    {2, 'd'},
    {3, 'r'},
    {4, 't'}
};

#endif /* !FLAGS_H_ */
