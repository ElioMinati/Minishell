/*
** EPITECH PROJECT, 2022
** my_is_alphachar
** File description:
** verify if char is alphabetical
*/

int my_is_num_char(char c)
{
    if (c < 48 || c > 58)
        return 0;
    return 1;
}

int my_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
