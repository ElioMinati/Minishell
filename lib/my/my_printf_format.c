/*
** EPITECH PROJECT, 2021
** my_printf_format.c
** File description:
** format functions for my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "bsprintf.h"

void display_arg_format(va_list args, char c, int format)
{
    if (c == 's')
        my_putstr2(va_arg(args, char *), format);
    if (c == 'i' || c == 'd')
        my_put_nbr2(va_arg(args, int), format);
    if (c == 'b')
        convert_to_binary_base(va_arg(args, int), format);
    if (c == 'o')
        print_octal_nbr(va_arg(args, int), format);
    if (c == 'X')
        print_hexa_maj_nbr(va_arg(args, int), format);
    if (c == 'u')
        my_put_nbr2(convert_neg_nbr(va_arg(args, int)), format);
    if (c == 'x')
        print_hexa_nbr(va_arg(args, int), format);
}

int is_flag_format(char c)
{
    if (c == 's' || c == 'i' || c == 'd' || c == 'b')
        return 0;
    if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
        return 0;
    return 1;
}

int go_after_format(va_list args, char const *str, int i)
{
    char *str2 = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int j = i; str[j] != '\0'; j++) {
        str2[j - i] = str[j];
    }
    if (str[i] == '.') {
        i++;
        for (; my_is_num_char(str[i]) == 1; i++);
        display_arg(args, str[i], my_getnbr(str2));
        return (i + 1);
    }
}
