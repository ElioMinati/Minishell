/*
** EPITECH PROJECT, 2022
** exec_multiple_pipes
** File description:
** execute multiple pipes in same command
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "mysh.h"
#include "my.h"

static char ***get_pipe_commands(char **av)
{
    int i;
    int j;
    char **av_cpy = my_arrdup(av);
    char ***pipe_cmd = malloc((my_nb_str_in_arr(av, "|") + 2) *
    sizeof(char **));

    for (i = 0; i < my_nb_str_in_arr(av_cpy, "|"); ++i) {
        for (j = 0; my_strcmp(av[j], "|") == 0; ++j);
        pipe_cmd[i] = get_before_pipe(av, j);
        av = my_dup_array(av, j + 1);
    }
    pipe_cmd[i] = my_arrdup(av);
    pipe_cmd[i + 1] = NULL;
    return pipe_cmd;
}

static void do_individual_pipe(char ***pipe_cmd, int i, char **env, int is_bin)
{
    pid_t main_pid;
    pid_t pipe_pid;
    int fd[2];

    pipe(fd);
    main_pid = fork();
    if (main_pid == 0) {
        detect_binary_stdout(pipe_cmd[i], env, fd, is_bin);
    }
    pipe_pid = fork();
    if (pipe_pid == 0) {
        detect_binary_stdin(pipe_cmd[i + 1], env, fd, is_bin);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(main_pid, NULL, 0);
    waitpid(pipe_pid, NULL, 0);
    exit(0);
}

void close_pipe_ends(int fd[2])
{
    close(fd[0]);
    close(fd[1]);
}

void exec_multiple_pipes(char **av, char **env, int is_bin)
{
    int i;
    char ***pipe_cmd = get_pipe_commands(av);
    int fd2[2];
    pid_t random_pid;
    pid_t other_random_pid;

    pipe(fd2);
    random_pid = fork();
    if (random_pid == 0) {
        dup2(fd2[1], STDOUT_FILENO);
        for (i = 0; pipe_cmd[i + 1] != NULL; ++i)
            do_individual_pipe(pipe_cmd, i, env, is_bin);
        close_pipe_ends(fd2);
    }
    other_random_pid = fork();
    if (other_random_pid == 0)
        detect_binary_stdin(pipe_cmd[i], env, fd2, is_bin);
    close_pipe_ends(fd2);
    waitpid(random_pid, NULL, 0);
    waitpid(other_random_pid, NULL, 0);
}
