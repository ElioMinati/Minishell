/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy str to another on
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i <= my_strlen(src); i++)
        dest[i] = src[i];
    return (dest);
}

char *my_strdup(char *src)
{
    char *dest = malloc((my_strlen(src) + 1) * sizeof(char));

    for (int i = 0; i <= my_strlen(src); i++)
        dest[i] = src[i];
    return dest;
}
