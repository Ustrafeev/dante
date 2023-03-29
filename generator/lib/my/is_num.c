/*
** EPITECH PROJECT, 2022
** bazard
** File description:
** is_num.c
*/

int is_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0;
    }
    return 1;
}
