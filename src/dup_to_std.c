/*
** EPITECH PROJECT, 2022
** dup_to_std.c
** File description:
** functions used to do more stuff pipe related
*/

#include <unistd.h>
#include "my.h"

void bin_dup_to_stdout(char *where, char **before, char **env, int fd[2])
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execve(my_strconcat(where, before[0]), before, env);
}

void bin_dup_to_stdin(char *where, char **after, char **env, int fd[2])
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execve(my_strconcat(where, after[0]), after, env);
}

void dup_to_stdout(char **before, char **env, int fd[2])
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execve(before[0], before + 1, env);
}

void dup_to_stdin(char **after, char **env, int fd[2])
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execve(after[0], after + 1, env);
}
