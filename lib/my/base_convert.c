/*
** EPITECH PROJECT, 2021
** base_convert
** File description:
** convert numbers into different bases
*/

#include <stdlib.h>
#include "bsprintf.h"

void convert_to_binary_base(int nb, int format)
{
    int i;
    int signed_nb = convert_neg_nbr(nb);
    char *result;

    for (i = 0; signed_nb >= my_compute_power_rec(2, i); i++);
    i--;
    result = malloc((i + 1)* sizeof(char));
    for (int j = 0; i >= 0; i--) {
        if ((signed_nb - my_compute_power_rec(2, i)) < 0) {
            result[j] = '0';
        } else {
            result[j] = '1';
            signed_nb = signed_nb - my_compute_power_rec(2, i);
        }
        j++;
    }
    for (int i = 0; format - i > my_strlen(result); i++)
        my_putchar('0');
    my_putstr(result);
    free(result);
}

void put_base_8_in_str(int nb)
{
    my_putchar('\\');
    print_octal_nbr(nb, 3);
}

void if_not_ascii_convert_to_octal_base(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            put_base_8_in_str(str[i]);
            continue;
        }
        my_putchar(str[i]);
    }
}

char get_nbr_or_char_hexa(int nb, int is_maj)
{
    int mod = nb % 10;

    if (nb >= 10 && is_maj == 0)
        return ('a' + mod);
    if (nb >= 10 && is_maj == 1)
        return ('A' + mod);
    return (nb + '0');
}

void print_hexa_nbr(int nb, int format)
{
    int i;
    int nb1 = convert_neg_nbr(nb);
    char *result;
    char c;

    verify_if_0(nb1);
    i = init_i(nb1);
    result = malloc((i + 1) * sizeof(char));
    for (int j = i; i >= 0; i--) {
        c = get_nbr_or_char_hexa(nb1 / my_compute_power_rec(16, i), 0);
        result[j - i] = c;
        nb1 = sub_nb1(nb1, c, 0, i);
    }
    for (int i = 0; format - i > my_strlen(result); i++)
        my_putchar('0');
    if (convert_neg_nbr(nb) >= 1)
        my_putstr(result);
    free(result);
}
