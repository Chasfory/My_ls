/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** Lib
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int nb_word(char a)
{
    if ((a >= 'a' && a <= 'z') || (a <= 'Z' && a >= 'A'))
        return (1);
    if (a <= '9' && a >= '0')
        return (1);
    return (0);
}

int words(char const *str)
{
    int i = 0;
    int words = 0;

    while (str[i] != '\0') {
        if (nb_word(str[i]) == 0 && nb_word(str[i + 1]) == 1) {
            words++;
        }
        while (nb_word(str[i]) == 1 && nb_word(str[i + 1]) == 1) {
            i++;
            }
    }
    return (words);

}

char **str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *) * (nb_words(str) + 1));
}