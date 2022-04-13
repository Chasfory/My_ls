/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** semestre1
*/

#include "my_lib_ls.h"

int main(int ac, char **av)
{
    if (ac == 0)
        return (84);
    if (ac == 1) {
        my_simple_ls(opendir("./"));
        return (0);
    }
    if (ac == 2 && av[1][0] != '-') {
        my_simple_ls(opendir(av[1]));
        return (0);
    }
    if (av[1][0] == '-' && av[1][1] == 'l') {
        if (ac == 2)
            my_lsl(av, ac);
        else
            my_spe_ls(av, ac);
    }
    return (84);
}