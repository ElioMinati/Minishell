/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <stdlib.h>
#include <stdarg.h>
#include "bsprintf.h"

void continue_ifs(va_list args, char c)
{
    if (c == 'X')
        print_hexa_maj_nbr(va_arg(args, int), -1);
    if (c == 'u')
        my_put_nbr(convert_neg_nbr(va_arg(args, int)));
    if (c == 'x')
        print_hexa_nbr(va_arg(args, int), -1);
}

void display_arg(va_list args, char c, int format)
{
    if (format < 0) {
        if (c == 's')
            my_putstr(va_arg(args, char *));
        if (c == 'c')
            my_putchar(va_arg(args, int));
        if (c == 'i' || c == 'd')
            my_put_nbr(va_arg(args, int));
        if (c == 'b')
            convert_to_binary_base(va_arg(args, int), -1);
        if (c == 'S')
            if_not_ascii_convert_to_octal_base(va_arg(args, char *));
        if (c == '%')
            my_putchar('%');
        if (c == 'o')
            print_octal_nbr(va_arg(args, int), -1);
        continue_ifs(args, c);
    } else {
        display_arg_format(args, c, format);
    }
}

int is_flag(char c)
{
    if (c == 's' || c == 'c' || c == 'i' || c == 'd' || c == 'b')
        return 0;
    if (c == 'S' || c == '%' || c == 'o' || c == 'u' || c == 'p')
        return 0;
    if (c == 'x' || c == 'X')
        return 0;
    return 1;
}

int is_format_flag(char const *str, int i)
{
    if (str[i] == '.') {
        i++;
        for (; my_is_num_char(str[i]) == 1; i++);
        if (is_flag_format(str[i]) == 0)
            return 0;
    }
    return 1;
}

int my_printf(char const *str, ...)
{
    va_list args;
    int count;

    va_start(args, str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '%' && is_flag(str[i + 1]) == 0) {
            display_arg(args, str[i + 1], -1);
            i++;
            continue;
        }
        if (str[i] == '%' && is_format_flag(str, i + 1) == 0) {
            i = go_after_format(args, str, i + 1);
        }
        my_putchar(str[i]);
        if (str[i] == '%' && str[i + 1] != '.') {
            i++;
        }
    }
    va_end(args);
    return 0;
}
