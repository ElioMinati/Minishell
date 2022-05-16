/*
** EPITECH PROJECT, 2022
** count_columns
** File description:
** counts collumns in an str
*/

int is_good_char_col(char c)
{
    if (c == ':' || c == '\0')
        return 1;
    if (c >= 33 && c <= 126)
        return 0;
    return 1;
}

int count_columns(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ':' && i != 0)
            ++count;
    }
    return count;
}
