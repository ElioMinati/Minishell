/*
** EPITECH PROJECT, 2022
** int_to_str
** File description:
** transform integer to str
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_int_to_str(int nb)
{
    int last;
    int count = 0;
    int if1 = 0;
    char *str = malloc(15 * sizeof(char));

    if (nb < 0) {
        if1 = 1;
        nb = nb * (-1);
    }
    for (; nb >= 10; count++) {
        last = (nb % 10);
        nb = (nb - last) / 10;
        str[count] = last + '0';
    }
    str[count] = '0' + nb % 10;
    if (if1 == 1)
        str[count++] = '-';
    str[count + 1] = '\0';
    my_revstr(str);
    return (str);
}
