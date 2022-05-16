/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** reproduce the my_strncmp function of linux
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (my_strlen(s1) < n || my_strlen(s2) < n) {
        if (my_strlen(s1) != my_strlen(s2))
            return 0;
    }
    for (int i = 0; s1[i] != '\0' && i < n; ++i) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
