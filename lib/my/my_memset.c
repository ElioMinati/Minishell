/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** put 0 in front of numbers
*/

#include <stdlib.h>

char *my_int_to_str(int nb);

char *my_revstr(char *str);

int my_getnbr(char const *str);

int my_is_num_char(char c);

char *my_int_memset(int nb, int wanted_size)
{
    int i;
    char *str = malloc(wanted_size * sizeof(char));

    str = my_int_to_str(nb);
    str = my_revstr(str);
    for (i = 0; i < wanted_size; ++i) {
        if (my_is_num_char(str[i]) == 0) {
            str[i] = '0';
        }
    }
    return my_revstr(str);
}
