/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** minishell shell program
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int do_shell(char *input, char **nenv)
{
    input = handle_tabs(input);
    if (input_handler(input, nenv) == -1)
        return -1;
    return 0;
}

static int free_inputs(char *input, char **inputs)
{
    free(input);
    free(inputs);
    return 0;
}

char **get_new_env(char **inputs, int i, char **nenv)
{
    return (is_malloc_needed(inputs[i], nenv) == 1 ?
    env_copy(nenv) : nenv);
}

void mysh(char **env)
{
    char **inputs = NULL;
    char *input = NULL;
    char **nenv = my_arrdup(env);
    size_t len = 0;

    while (1) {
        my_putstr("$>");
        if (getline(&input, &len, stdin) == -1)
            break;
        input = handle_tabs(input);
        inputs = my_str_to_word_array_sc(input);
        for (int i = 0; inputs[i] != NULL; ++i) {
            nenv = get_new_env(inputs, i, nenv);
            do_shell(inputs[i], nenv);
        }
        len = free_inputs(input, inputs);
    }
}
