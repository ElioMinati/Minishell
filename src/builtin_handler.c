/*
** EPITECH PROJECT, 2022
** builtin handler
** File description:
** functions used to handle builtin commands of shell
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static void set_env_handler(char **cmd, char **env)
{
    if (my_arrlen(cmd) != 2 && my_arrlen(cmd) != 3)
        write(2, "Error: Invalid number of parameters.\n", 37);
    else if (my_arrlen(cmd) == 2)
        set_env(cmd[1], NULL, env, 0);
    else
        set_env(cmd[1], cmd[2], env, 1);
}

void env_handler(char **cmd, char **env)
{
    if (my_strcmp(cmd[0], "env") == 1) {
        for (int i = 0; env[i] != NULL; ++i) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
    }
    if (my_strcmp(cmd[0], "setenv") == 1) {
        set_env_handler(cmd, env);

    }
    if (my_strcmp(cmd[0], "unsetenv") == 1) {
        unset_env(cmd, env);
    }
}

int builtin_handler(char **cmd, char **env)
{
    if (my_strcmp(cmd[0], "cd") == 1) {
        change_dir(cmd, env);
    }
    if (my_strcmp(cmd[0], "cd-") == 1) {
        interchange_pwd(env);
    }
    env_handler(cmd, env);
    if (my_strcmp(cmd[0], "exit") == 1)
        exit(0);
    return 0;
}
