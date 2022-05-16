/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get number from string
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            neg = neg * (-1);
        }
        i++;
    }
    while (my_is_num_char(str[i]) == 1) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return (number * neg);
}
