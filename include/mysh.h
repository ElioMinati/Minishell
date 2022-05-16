/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** header for mysh with prototypes
*/

#ifndef MYSH_H_
    #define MYSH_H_

int input_handler(char *input, char **env);

char *handle_tabs(char *input);

char **get_path(char **env);

void set_env(char *option, char *value, char **env, int is_value);

void change_dir(char **cmd, char **env);

char *get_correct_path(char **paths, char *command);

char **env_copy(char **env);

int get_old_pwd_pos(char **env);

int builtin_handler(char **cmd, char **env);

char *get_home_path(char **env);

char **my_arrdup(char **arr);

void unset_env(char **options, char **env);

void set_str(char *str);

void mysh(char **env);

int is_malloc_needed(char *input, char **env);

int is_char_same(char c, char s);

int verify_opt(char *option);

char *get_value(char **env, char *opt);

int get_id_opt(char **env, char *opt);

void interchange_pwd(char **env);

int is_directory(char *dirname);

int verify_opt(char *option);

int is_pipe_in_array(char **av, char **env, int is_bin);

void dup_to_stdout(char **before, char **env, int fd[2]);

void dup_to_stdin(char **after, char **env, int fd[2]);

void bin_dup_to_stdout(char *where, char **before, char **env, int fd[2]);

void bin_dup_to_stdin(char *where, char **after, char **env, int fd[2]);

void detect_binary_stdout(char **before, char **env, int fd[2], int is_bin);

void detect_binary_stdin(char **after, char **env, int fd[2], int is_bin);

void status_handler(int status);

char **get_after_pipe(char **av, int len);

char **get_before_pipe(char **av, int len);

void exec_multiple_pipes(char **av, char **env, int is_bin);

char **my_dup_array(char **array, int offset);

int is_redirection_in_array(char **av, char **env, int is_bin);

void exec_pipe(char **before, char **after, char **env, int is_bin);

void setenv_cond(char **env, char *opt, char *value, int is_value);

#endif /* !MYSH_H_ */
