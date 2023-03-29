/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** displays an integer
*/

#include "../../inc/lib.h"

int my_find_power(int nb)
{
    int power;

    power = 1;
    while (nb >= power) {
        power = power * 10;
    }
    return (power / 10);
}

int my_put_nbr(int nb)
{
    int divide;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    } else if (nb == 0) {
        my_putchar('0');
    }
    divide = my_find_power(nb);

    while (divide >= 1) {
        my_putchar((nb / divide) + 48);
        nb = nb % divide;
        divide = divide / 10;
    }
    return (0);
}

int my_put_nbr_unsigned(unsigned int nb, int len)
{
    if (nb >= 10) {
        len += my_put_nbr_unsigned(nb / 10, len);
    }
    my_putchar(nb % 10 + 48);
    len++;
    return (len);
}
