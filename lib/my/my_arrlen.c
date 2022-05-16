/*
** EPITECH PROJECT, 2022
** my_arrlen.c
** File description:
** function that returns the length of an array
*/

#include <unistd.h>

int my_arrlen(char **arr)
{
    int i;

    for (i = 0; arr[i] != NULL; ++i);
    return i;
}
