/*
** EPITECH PROJECT, 2022
** my_nb_str_in_arr
** File description:
** count number of occurences of str in array
*/

#include <unistd.h>
#include "my.h"

int my_nb_str_in_arr(char **array, char *needle)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; ++i) {
        if (my_strcmp(array[i], needle))
            ++count;
    }
    return count;
}
