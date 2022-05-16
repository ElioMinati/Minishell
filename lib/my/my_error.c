/*
** EPITECH PROJECT, 2022
** my_error.c
** File description:
** prints a message on the error output
*/

#include <unistd.h>
#include "my.h"

void my_error(char *str)
{
    write(2, str, my_strlen(str));
}
