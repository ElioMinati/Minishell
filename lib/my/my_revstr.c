/*
** EPITECH PROJECT, 2022
** reverse string
** File description:
** function that reverses a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int j = 0;
    char *dest = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int i = my_strlen(str) - 1; i >= 0; --i, ++j) {
        dest[j] = str[i];
    }
    dest[my_strlen(str)] = '\0';
    return dest;
}
