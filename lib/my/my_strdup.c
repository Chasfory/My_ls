/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** infinadd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(const char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    return my_strcpy(str, src);
}
