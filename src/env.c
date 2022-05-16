/*
** EPITECH PROJECT, 2022
** env.c
** File description:
** all functions env related
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

int does_opt_exist(char **env, char *option)
{
    for (int i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], option, my_strlen(option)) == 1 &&
        env[i][my_strlen(option)] == '=')
            return i;
    }
    return -1;
}

char **env_copy(char **env)
{
    int i;
    char **dest = malloc((my_arrlen(env) + 2) * sizeof(char *));

    for (i = 0; env[i] != NULL; ++i) {
        dest[i] = malloc((my_strlen(env[i]) + 1) * sizeof(char));
        my_strcpy(dest[i], env[i]);
    }
    dest[i] = NULL;
    dest[i + 1] = NULL;
    return dest;
}

void set_env(char *option, char *value, char **env, int is_value)
{
    char *opt = my_strconcat(option, "=");

    if (verify_opt(option) == -1) {
        my_error(
        "setenv: Variable name must contain alphanumeric characters.\n");
        return;
    }
    if (does_opt_exist(env, option) == -1) {
        setenv_cond(env, opt, value, is_value);
    } else {
        if (is_value == 1)
            env[does_opt_exist(env, option)] = my_strconcat(opt, value);
        else
            env[does_opt_exist(env, option)] = opt;
    }
}

void remove_opt_env(char *option, char **env)
{
    int i;
    int exists = 0;

    for (i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], option, my_strlen(option)) == 1) {
            exists = 1;
            break;
        }
    }
    if (exists == 0) {
        write(2, "Error: invalid environment option.\n", 35);
        return;
    }
    for (; env[i] != NULL; ++i)
        env[i] = env[i + 1];
}

void unset_env(char **options, char **env)
{
    for (int i = 1; options[i] != NULL; ++i)
        remove_opt_env(options[i], env);
}
