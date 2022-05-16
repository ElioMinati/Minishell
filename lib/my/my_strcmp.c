/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** reproduce the linux my_strcmp function but our one
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}