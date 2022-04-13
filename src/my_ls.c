/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** semestre1
*/

#include "my_lib_ls.h"

int my_simple_ls(DIR *open)
{
    struct dirent *read;

    if (open == NULL)
        return (84);
    while ((read = readdir(open)) != 0) {
        if (read->d_name[0] != '.') {
            my_putstr(read->d_name);
            my_putstr("  ");
        }
    }
    my_putchar('\n');
    if (closedir(open) == -1)
        return (84);
    return (0);
}