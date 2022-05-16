/*
** EPITECH PROJECT, 2022
** my_count_char.c
** File description:
** count the nb of characters in str
*/

int my_count_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c)
            ++count;
    }
    return count;
}
