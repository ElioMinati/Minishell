/*
** EPITECH PROJECT, 2021
** base_convert.c
** File description:
** functions used to convert bases for my_printf
*/

#include <stdlib.h>
#include "bsprintf.h"

void print_hexa_maj_nbr(int nb, int format)
{
    int i;
    int nb1 = convert_neg_nbr(nb);
    char *result;
    char c;

    verify_if_0(nb1);
    i = init_i(nb1);
    result = malloc((i + 1) * sizeof(char));
    for (int j = i; i >= 0; i--) {
        c = get_nbr_or_char_hexa(nb1 / my_compute_power_rec(16, i), 1);
        result[j - i] = c;
        nb1 = sub_nb1(nb1, c, 1, i);
    }
    for (int i = 0; format - i > my_strlen(result); i++)
        my_putchar('0');
    if (convert_neg_nbr(nb) >= 1)
        my_putstr(result);
    free(result);
}

int sub_nb1(int nb1, char c, int is_maj, int i)
{
    c = hex_to_dec(c, is_maj);
    nb1 = nb1 - c * my_compute_power_rec(16, i);
    return nb1;
}

void verify_if_0(int nb)
{
    if (nb == 0) {
        my_putchar('0');
    }
}
