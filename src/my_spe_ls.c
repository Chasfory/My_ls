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

void total_block(char **av, int i)
{
    struct stat total;
    struct dirent *read = NULL;
    int nb = 0;
    DIR *open = opendir(av[i]);

    if (open == NULL)
        return;
    while ((read = readdir(open)) != NULL) {
        stat(read->d_name, &total);
        if (read->d_name[0] != '.') {
            nb = total.st_blocks + nb;
        }
    }
    closedir(open);
    my_putstr("total ");
    my_put_nbr(nb / 2);
    my_putchar('\n');
}

void display_tempo(struct stat stats)
{
    struct tm *time = NULL;
    char *tempo;

    tempo = ctime(&stats.st_ctime);
        for (int i = 4;  i <= 15; i++) {
            my_putchar(tempo[i]);
        }
    my_putchar(' ');
}

void display_bis(struct stat stats)
{
    struct passwd *gw = NULL;
    struct group *gp = NULL;
    int str = 0;

    gw = getpwuid(stats.st_uid);
    my_putstr(gw->pw_name);
    my_putchar(' ');
    gp = getgrgid(stats.st_gid);
    my_putstr(gp->gr_name);
    my_putchar(' ');
    str = stats.st_size;
    my_put_nbr(str);
    my_putchar(' ');
    display_tempo(stats);
}

void display(struct stat stats)
{
    int str = 0;

    my_putstr((S_ISREG(stats.st_mode)) ? "-" : "d");
    my_putstr((stats.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((stats.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((stats.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((stats.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((stats.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((stats.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((stats.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((stats.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((stats.st_mode & S_IXOTH) ? "x" : "-");
    my_putchar('.');
    my_putchar(' ');
    str = stats.st_nlink;
    my_put_nbr(str);
    my_putchar(' ');
    display_bis(stats);
}

int my_spe_ls(char **av, int ac)
{
    struct stat stats = {0};
    struct dirent *read = NULL;
    struct stat fonct = {0};
    DIR *open;

    for (int i = 2; i < ac; i++) {
        open = opendir(av[i]);
        if (open == NULL)
            return (84);
        print_debut(av[i]);
        total_block(av, i);
        stat(av[i], &stats);
        my_spe_ls_bis(fonct, read, open, av[i]);
        if (closedir(open) == -1)
            return (84);
        if ((i + 1) < ac)
            my_putchar('\n');
    }
    return (0);
}