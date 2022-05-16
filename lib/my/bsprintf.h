/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** contains all prototypes of my library
*/

#include <stdarg.h>

#ifndef BSPRINTF_H_
    #define BSPRINTF_H_

void my_putchar(char c);

int my_putstr(char const *str);

char *my_revstr(char *str);

char *int_to_str(int nb);

void my_put_nbr(int nb);

int my_strlen(char const *str);

int my_printf(char const *str, ...);

char *my_strcpy(char *dest, char const *src);

int my_compute_power_rec(int nb, int p);

char *int_to_str(int nb);

void convert_to_binary_base(int nb, int format);

void put_base_8_in_str(int nb);

void if_not_ascii_convert_to_octal_base(char *str);

void print_octal_nbr(int nb, int format);

char *return_octal_nbr(int nb);

void my_put_nbr(int nb);

int hex_to_dec(int nb, int is_maj);

void print_hexa_nbr(int nb, int format);

int init_i(int nb);

void display_hexa(char *result);

void print_hexa_maj_nbr(int nb, int format);

char get_nbr_or_char_hexa(int nb, int is_maj);

int sub_nb1(int nb1, char c, int is_maj, int i);

void verify_if_0(int nb);

int convert_neg_nbr(int nb);

int go_after_format(va_list args, char const *str, int i);

int my_is_num_char(char c);

int my_getnbr(char const *str);

void display_arg(va_list args, char c, int format);

void my_put_nbr2(int nb, int format);

int my_putstr2(char const *str, int format);

void display_arg_format(va_list args, char c, int format);

int is_flag_format(char c);

#endif /* BSPRINTF_H_ */
