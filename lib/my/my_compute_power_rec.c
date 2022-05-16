/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** recursive function that returns the parameter to the power of the other one
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return 0;
    else if (p == 0)
        return 1;
    return (nb * my_compute_power_rec(nb, p - 1));
}
