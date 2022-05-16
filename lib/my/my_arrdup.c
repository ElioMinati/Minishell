/*
** EPITECH PROJECT, 2022
** my_arrdup
** File description:
** duplicate an array into another
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **my_arrdup(char **arr)
{
    int i;
    char **dest = malloc((my_arrlen(arr) + 1) * sizeof(char *));

    for (i = 0; arr[i] != NULL; ++i) {
        dest[i] = malloc ((my_strlen(arr[i]) + 1) * sizeof(char));
        my_strcpy(dest[i], arr[i]);
    }
    dest[i] = NULL;
    return dest;
}

char **my_dup_array(char **array, int offset)
{
    int i;
    char **dest = malloc((my_arrlen(array) - offset + 1) * sizeof(char *));

    for (i = 0; i < (my_arrlen(array) - offset); ++i) {
        dest[i] = my_strdup(array[i + offset]);
    }
    dest[i] = NULL;
    return dest;
}
