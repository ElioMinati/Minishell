/*
** EPITECH PROJECT, 2022
** strconcat
** File description:
** function that concatenates two strings
*/

#include <stdlib.h>
#include "my.h"

char *my_strconcat(char *str, char *str2)
{
    int i;
    char *dest = malloc((my_strlen(str) + my_strlen(str2) + 1) * sizeof(char));

    for (i = 0; str[i] != '\0'; ++i)
        dest[i] = str[i];
    for (int j = 0; str2[j] != '\0'; ++j, ++i)
        dest[i] = str2[j];
    dest[i] = '\0';
    return dest;
}
