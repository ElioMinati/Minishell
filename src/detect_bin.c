/*
** EPITECH PROJECT, 2022
** detect_bin.c
** File description:
** functions used to detect a binary
*/

#include <stdlib.h>
#include "mysh.h"

void detect_binary_stdout(char **before, char **env, int fd[2], int is_bin)
{
    char *where = get_correct_path(get_path(env), before[0]);

    if (is_bin == 1)
        bin_dup_to_stdout(where, before, env, fd);
    else
        dup_to_stdout(before, env, fd);
    free(where);
}

void detect_binary_stdin(char **after, char **env, int fd[2], int is_bin)
{
    char *where = get_correct_path(get_path(env), after[0]);

    if (is_bin == 1)
        bin_dup_to_stdin(where, after, env, fd);
    else
        dup_to_stdin(after, env, fd);
    free(where);
}
