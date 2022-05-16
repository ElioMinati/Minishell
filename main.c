/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for minishell1
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int main(int ac, char **av, char **env)
{
    (void) av;

    if (ac != 1)
        return 84;
    mysh(env);
    return 0;
}
