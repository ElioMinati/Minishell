/*
** EPITECH PROJECT, 2021
** base convert2
** File description:
** second file of base convert functions for my_printf
*/

#include <stdlib.h>
#include "bsprintf.h"

void print_octal_nbr(int nb, int format)
{
    int i;
    int nb1 = convert_neg_nbr(nb);
    char *result;

    verify_if_0(nb1);
    for (i = 0; nb1 >= my_compute_power_rec(8, i); i++);
    i--;
    result = malloc((i + 1) * sizeof(char));
    for (int j = 0; i >= 0; i--) {
        result[j] = nb1 / my_compute_power_rec(8, i) + '0';
        nb1 = nb1 - (result[j] - '0') * my_compute_power_rec(8, i);
        j++;
    }
    for (int i = 0; (format - i) > (my_strlen(result)); i++)
        my_putchar('0');
    if (nb != 0)
        my_putstr(result);
    free(result);
}

int hex_to_dec(int nb, int is_maj)
{
    if (nb >= '0' && nb <= '9')
        return (nb - '0');
    if (is_maj == 0)
        return (10 + nb - 'a');
    if (is_maj == 1)
        return (10 + nb - 'A');
}

int init_i(int nb)
{
    int i;

    for (i = 0; nb >= my_compute_power_rec(16, i); i++);
    i--;
    return i;
}

int convert_neg_nbr(int nb)
{
    if (nb < 0)
        nb = nb * (-1);
    return nb;
}
