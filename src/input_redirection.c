/*
** EPITECH PROJECT, 2022
** input_redirection.c
** File description:
** functions used for input redirections
*/

#include <unistd.h>
#include "mysh.h"

int is_redirection_in_array(char **av, char **env, int is_bin)
{
    for (int i = 0; av[i] != NULL; ++i) {
        if (my_strcmp(av[i], "<")) {
            exec_pipe(get_after_pipe(av, i), get_before_pipe(av, i), env,
            is_bin);
            return 1;
        }
    }
    return 0;
}
