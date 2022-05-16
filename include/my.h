/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** contains all prototypes of my library
*/

#include <stdarg.h>
#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_atoi(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

int my_is_num_char(char c);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_is_prime1(int nb);

int my_compare(char const *s1, char const *s2);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

char *my_strstr_pt2 (char *str, char const *to_find, int i);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int verify_is_str_num(char *str);

char *my_int_to_str(int nb);

char *my_int_memset(int nb, int wanted_size);

char **my_str_to_word_array(char *str);

void my_str_to_ptr_array(char *str, char *array[]);

int count_spaces(char *str);

int is_good_char(char c);

int is_good_char_col(char c);

int count_columns(char *str);

char *my_strconcat(char *str, char *str2);

char **my_str_to_word_array_nt(char *str);

int my_arrlen(char **arr);

int my_printf(char const *str, ...);

int count_line_jumps(char *str);

int my_is_alpha(char c);

void my_error(char *str);

int my_is_num_char(char c);

void my_error(char *str);

char *my_strdup(char *src);

int my_count_char(char *str, char c);

void go_after_space_tabs(char *str);

char **my_str_to_word_array_sc(char *str);

int my_nb_str_in_arr(char **array, char *needle);

#endif /* MY_H_ */
