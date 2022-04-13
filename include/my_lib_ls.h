/*
** EPITECH PROJECT, 2021
** my_ls.h
** File description:
** semestre1
*/

#ifndef _MY_LIB_LS_H_
#define _MY_LIB_LS_H_

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdio.h>
#include "my.h"

int my_simple_ls(DIR *open);
int my_spe_ls(char **av, int ac);
char *file_to_folder(char *av, char *read);
void total_block(char **av, int i);
void display_tempo(struct stat stats);
void display_bis(struct stat stats);
void display(struct stat stats);
int my_spe_ls_bis(struct stat fonct, struct dirent *read, DIR *open, char *a);
void total_block_ls(char **av);
int my_lsl(char **av, int ac);
void print_debut(char *av);

#endif /*MY_LIB_LS_H_*/
