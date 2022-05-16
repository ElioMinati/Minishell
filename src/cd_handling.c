/*
** EPITECH PROJECT, 2022
** do_cd builtin
** File description:
** functions used to complete the cd builtin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"

static int does_file_exists(char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}

int is_directory(char *dirname)
{
    struct stat st;

    stat(dirname, &st);
    if (S_ISDIR(st.st_mode)) {
        return 1;
    }
    return 0;
}

void change_pwd(char **env, char **cmd)
{
    int oldpwd = get_old_pwd_pos(env);
    char *newpwd;
    int len;
    int i;

    if (oldpwd == -1)
        oldpwd = my_arrlen(env);
    for (i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], "PWD", 3))
            break;
    }
    len = my_strlen(env[i]) + my_strlen(cmd[1]);
    newpwd = malloc(len * sizeof(char));
    chdir(cmd[1]);
    env[oldpwd] = my_strconcat("OLD", env[i]);
    env[i] = my_strconcat("PWD=", getcwd(newpwd, len));
}

void cd_error_handler(char **cmd)
{
    if (does_file_exists(cmd[1]) == 0) {
        write(2, "cd: ", 4);
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": No such file or directory\n", 28);
        return;
    }
    if (is_directory(cmd[1]) == 0) {
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": Not a directory.\n", 20);
        return;
    }
    if (access(cmd[1], R_OK) == -1) {
        write(2, "cd: ", 4);
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": Permission denied\n", 20);
        return;
    }
}

void change_dir(char **cmd, char **env)
{
    if (cmd[1] == NULL || (cmd[1][0] == '~' && cmd[1][1] == '\0')) {
        cmd[1] = malloc((my_strlen(get_home_path(env)) + 1) * sizeof(char));
        my_strcpy(cmd[1], get_home_path(env));
    }
    if (my_strcmp(cmd[1], "-") == 1) {
        interchange_pwd(env);
        return;
    }
    if (my_strcmp(cmd[0], "cd") == 1) {
        if (access(cmd[1], R_OK) == 0 && is_directory(cmd[1]) == 1) {
            change_pwd(env, cmd);
        } else
            cd_error_handler(cmd);
    }
}
