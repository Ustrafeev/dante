/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** displays a character
*/

#include "../../inc/lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
