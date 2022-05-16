/*
** EPITECH PROJECT, 2022
** get.c
** File description:
** functions used to get stuff
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char **split_paths(char *str)
{
    int i;
    int ccount = count_columns(str) + 1;
    char **paths = malloc((ccount + 1) * sizeof(char *));

    for (i = 0; i < ccount; ++i)
        paths[i] = malloc((my_strlen(str) + 2) * sizeof(char));
    paths[i] = NULL;
    for (int j = 0; j < ccount; ++j) {
        for (i = 0; is_good_char_col(str[0]) == 0; ++i) {
            paths[j][i] = str[0];
            str++;
        }
        paths[j][i] = '/';
        paths[j][i + 1] = '\0';
        set_str(str);
        while (str[0] == ':')
            str++;
    }
    return paths;
}

char *get_home_path(char **env)
{
    char *home;
    int i;

    for (i = 0; env[i] != NULL; ++i) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
        && env[i][3] == 'E' && env[i][4] == '=')
            break;
    }
    home = malloc((my_strlen(env[i]) + 1) * sizeof(char));
    my_strcpy(home, env[i]);
    for (int j = 0; j < 5; ++j)
        ++home;
    return home;
}

char **get_path(char **env)
{
    char *p;
    char **paths;
    int i;

    for (i = 0; env[i] != NULL; ++i) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H' && env[i][4] == '=')
            break;
    }
    p = malloc((my_strlen(env[i]) + 1) * sizeof(char));
    my_strcpy(p, env[i]);
    for (int j = 0; j < 5; ++j)
        ++p;
    paths = split_paths(p);
    return paths;
}

char *get_correct_path(char **paths, char *command)
{
    for (int i = 0; paths[i] != NULL; ++i) {
        if (access(my_strconcat(paths[i], command), X_OK) == 0) {
            return paths[i];
        }
    }
    return NULL;
}

int get_old_pwd_pos(char **env)
{
    int i;

    for (i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], "OLDPWD", 6))
            return i;
    }
    return -1;
}
