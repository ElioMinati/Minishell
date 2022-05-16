/*
** EPITECH PROJECT, 2022
** strcapitalize
** File description:
** capitalize every letter of each word in a string
*/

int my_strlen(char const *str);

char *my_strcapitalize(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i <= length; i++) {
        if (i == 0 && str[i] >= 97)
            str[0] = str[i] - 32;
        if (str[i] == ' ' && str[i + 1] > 91)
            str[i + 1] = str[i + 1] - 32;
    }
    return (str);
}
