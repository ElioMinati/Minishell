/*
** EPITECH PROJECT, 2022
** pipes.c
** File description:
** functions used to handle the pipes in mysh
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#include "mysh.h"

char **get_after_pipe(char **av, int len)
{
    char **dest = malloc((my_arrlen(av) - len + 1) * sizeof(char *));

    for (int i = 1; av[i + len] != NULL; ++i) {
        dest[i - 1] = my_strdup(av[i + len]);
    }
    dest[my_arrlen(av) - len] = NULL;
    return dest;
}

char **get_before_pipe(char **av, int len)
{
    char **dest = malloc((len + 1) * sizeof(char *));

    for (int i = 0; i < len; ++i) {
        dest[i] = my_strdup(av[i]);
    }
    dest[len] = NULL;
    return dest;
}

static void do_pipe(char **before, char **after, char **env, int is_bin)
{
    int fd[2];
    pid_t main_pid;
    pid_t pipe_pid;

    pipe(fd);
    main_pid = fork();
    if (main_pid == 0) {
        detect_binary_stdout(before, env, fd, is_bin);
    }
    pipe_pid = fork();
    if (pipe_pid == 0) {
        detect_binary_stdin(after, env, fd, is_bin);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(main_pid, NULL, 0);
    waitpid(pipe_pid, NULL, 0);
    exit(0);
}

void exec_pipe(char **before, char **after, char **env, int is_bin)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        do_pipe(before, after, env, is_bin);
    } else {
        waitpid(-1, &status, 0);
        status_handler(status);
    }
}

int is_pipe_in_array(char **av, char **env, int is_bin)
{
    if (my_nb_str_in_arr(av, "|") > 1) {
        exec_multiple_pipes(av, env, is_bin);
        return 1;
    }
    for (int i = 0; av[i] != NULL; ++i) {
        if (my_strcmp(av[i], "|")) {
            exec_pipe(get_before_pipe(av, i), get_after_pipe(av, i), env,
            is_bin);
            return 1;
        }
    }
    return 0;
}
