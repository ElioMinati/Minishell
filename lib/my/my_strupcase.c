/*
** EPITECH PROJECT, 2022
** strupcase
** File description:
** modify every letter of a string to upcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] - 32 < 65)
            continue;
        str[i] = str[i] - 32;
    }
    return (str);
}
