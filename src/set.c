/*
** EPITECH PROJECT, 2022
** autocomplete.c
** File description:
** functions that make possible autocompletion with tab
*/

#include <stdlib.h>
#include "my.h"

void set_str(char *str)
{
    if (str[0] != '\0')
        str++;
}

int go_after_sp_tb(char *input, int i)
{
    for (; input[i] == ' ' || input[i] == '\t'; ++i);
    return i;
}

char *handle_tabs(char *input)
{
    int i = go_after_sp_tb(input, 0);
    int j = 0;
    char *dest = malloc((my_strlen(input) + 1) * sizeof(char));

    for (; input[i] != '\0'; ++i) {
        if ((input[i] == ' ' || input[i] == '\t') && (input[i + 1] == ' ' ||
        input[i + 1] == '\t'))
            continue;
        if (input[i] == '\t')
            input[i] = ' ';
        dest[j] = input[i];
        ++j;
    }
    dest[j] = '\0';
    --j;
    for (; dest[j] == '\t' || dest[j] == ' '; --j)
        dest[j] = '\0';
    free(input);
    return dest;
}
