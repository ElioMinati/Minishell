/*
** EPITECH PROJECT, 2022
** verif.c
** File description:
** functions used to verify stuff
*/

#include "my.h"
#include "mysh.h"

int is_char_same(char c, char s)
{
    if (c == s)
        return -1;
    return 0;
}

int verify_opt(char *option)
{
    for (int i = 0; option[i] != '\0'; ++i) {
        if (my_is_alpha(option[i]) == 0 && my_is_num_char(option[i]) == 0)
            return -1;
    }
    return 1;
}

int is_malloc_needed(char *input, char **env)
{
    char **cmd = my_str_to_word_array_nt(input);

    if (my_strcmp(cmd[0], "setenv") == 1) {
        return 1;
    } else if (my_strcmp(cmd[0], "cd") == 1) {
        if (get_old_pwd_pos(env) == -1)
            return 1;
    }
    return 0;
}
