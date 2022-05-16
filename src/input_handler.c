/*
** EPITECH PROJECT, 2022
** input_handler
** File description:
** functions that handle the input of the minishell
*/

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

int is_builtin(char *name)
{
    if (my_strcmp(name, "cd") == 1)
        return 1;
    if (my_strcmp(name, "cd-") == 1)
        return 1;
    if (my_strcmp(name, "env") == 1)
        return 1;
    if (my_strcmp(name, "setenv") == 1)
        return 1;
    if (my_strcmp(name, "unsetenv") == 1)
        return 1;
    if (my_strcmp(name, "exit") == 1)
        return 1;
    return 0;
}

void status_handler(int status)
{
    if (__WCOREDUMP(status))
        write(STDERR_FILENO, "Segmentation fault\n", 19);
}

static void launch_exe(char *input, char **env)
{
    struct stat st;
    char **av = my_str_to_word_array_nt(input);
    pid_t pid;
    int status;

    av[0] + 2;
    if (stat(av[0], &st) == -1) {
        write(STDERR_FILENO, av[0], my_strlen(av[0]));
        my_error(": Command not found.\n");
        my_putchar('\n');
    } else {
        if (is_pipe_in_array(av, env, 0) || is_redirection_in_array(av, env, 0))
            return;
        pid = fork();
        if (pid == 0)
            execve(av[0], av + 1, env);
        waitpid(-1, &status, 0);
        kill(pid, SIGKILL);
        status_handler(status);
    }
}

static void launch_bin(char *input, char **env)
{
    char **av = my_str_to_word_array_nt(input);
    char **paths = get_path(env);
    char *where = get_correct_path(paths, av[0]);
    pid_t pid;
    int status;

    if (where == NULL) {
        write(STDERR_FILENO, av[0], my_strlen(av[0]));
        write(STDERR_FILENO, ": Command not found.\n", 21);
    } else {
        if (is_pipe_in_array(av, env, 1) || is_redirection_in_array(av, env, 1))
            return;
        pid = fork();
        if (pid == 0) {
            execve(my_strconcat(where, av[0]), av, env);
        }
        waitpid(-1, &status, 0);
        status_handler(status);
    }
}

int input_handler(char *input, char **env)
{
    char **cmd = my_str_to_word_array_nt(input);

    if (is_builtin(cmd[0])) {
        if (builtin_handler(cmd, env) == -1)
            return -1;
        return 0;
    }
    if (input[0] == '.' && input[1] == '/')
        launch_exe(input, env);
    else
        launch_bin(input, env);
    return 0;
}
