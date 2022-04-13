/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** semestre1
*/

#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_lib_ls.h"

void print_debut(char *av)
{
    int a;

    my_putstr(av);
    for (a = 0; av[a] != '\0'; a++);
        if (av[a - 1] == '/')
            my_putstr(":\n");
        else
            my_putstr("/:\n");
}

char *file_to_folder(char *av, char *read)
{
    char *str = malloc(sizeof(char) * (my_strlen(av) + my_strlen(read) + 2));
    int i = 0;

    str = my_strcpy(str, av);
    str = my_strcat(str, "/");
    str = my_strcat(str, read);
    return (str);
}

int my_spe_ls_bis(struct stat fonct, struct dirent *read, DIR *open, char *a)
{
    int ret = 0;
    char *str;

    while ((read = readdir(open)) != NULL) {
        if (read->d_name[0] != '.') {
            str = file_to_folder(a, read->d_name);
            ret = stat(str, &fonct);
            if (ret == -1)
                return (84);
            display(fonct);
            my_putstr(read->d_name);
            my_putchar('\n');
        }
    }
    return (0);
}

void total_block_ls(char **av)
{
    struct stat total = {0};
    struct dirent *read = NULL;
    int nb = 0;
    DIR *open;

    open = opendir("./");
    if (open == NULL)
        return;
    while ((read = readdir(open)) != NULL) {
        if (read->d_name[0] != '.') {
            stat(read->d_name, &total);
            nb = total.st_blocks + nb;
        }
    }
    closedir(open);
    my_putstr("total ");
    my_put_nbr(nb / 2);
    my_putchar('\n');
}

int my_lsl(char **av, int ac)
{
    struct stat stats = {0};
    struct dirent *read = NULL;
    DIR *open;

    open = opendir("./");
    if (open == NULL)
        return (84);
    total_block_ls(av);
    stat("./", &stats);
    while ((read = readdir(open)) != NULL) {
        if (read->d_name[0] != '.') {
            stat(read->d_name, &stats);
            display(stats);
            my_putstr(read->d_name);
            my_putchar('\n');
        }
    }
    if (closedir(open) == -1)
        return (84);
    return (0);
}