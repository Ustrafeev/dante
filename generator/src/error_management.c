/*
** EPITECH PROJECT, 2022
** dante
** File description:
** error_management.c
*/

#include "../inc/generator.h"

int error_handling(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return 1;
    if (!(is_num(argv[1]) || is_num(argv[2])))
        return 1;
    if (argc == 4 && strcmp(argv[3], "perfect"))
        return 1;
    return 0;
}
