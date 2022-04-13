/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** task01
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int p = 0;

    while (src[p] != '\0') {
        dest[p] = src[p];
        p++;
    }
    dest[p] = '\0';
    return dest;
}
