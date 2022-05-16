/*
** EPITECH PROJECT, 2022
** cd_get.c
** File description:
** get stuff in env for cd
*/

#include <unistd.h>
#include "my.h"

char *get_value(char **env, char *opt)
{
    char *dest = NULL;

    for (int i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], opt, my_strlen(opt))) {
            dest = my_strdup(env[i]);
            break;
        }
    }
    if (dest != NULL) {
        while (dest[0] != '=' && dest[0] != '\0')
            ++dest;
        ++dest;
    }
    return dest;
}

int get_id_opt(char **env, char *opt)
{
    for (int i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], opt, my_strlen(opt)))
            return i;
    }
    return -1;
}

void interchange_pwd(char **env)
{
    char *tmp = NULL;
    if (get_id_opt(env, "OLDPWD") == -1) {
        my_error("cd :OLDPWD not set.\n");
        return;
    }
    tmp = get_value(env, "PWD");
    env[get_id_opt(env, "PWD")] = my_strconcat("PWD=",
    get_value(env, "OLDPWD"));
    env[get_id_opt(env, "OLDPWD")] = my_strconcat("OLDPWD=", tmp);
}

void setenv_cond(char **env, char *opt, char *value, int is_value)
{
    if (is_value == 1)
        env[my_arrlen(env)] = my_strconcat(opt, value);
    else
        env[my_arrlen(env)] = opt;
}
