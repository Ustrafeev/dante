/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-nelly.pereira-alves
** File description:
** my_putchar.c
*/

#include "../../inc/generator.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putchar_two(char c)
{
    write(2, &c, 1);
    return 1;
}
