/*
** EPITECH PROJECT, 2022
** dante
** File description:
** main.c
*/

#include "inc/generator.h"

int main(int argc, char **argv)
{
    if (error_handling(argc, argv))
        return 84;
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int perfect = argc == 4;
    srand(time(NULL));
    show_maze(create_maze(width, height, perfect), width, height);
    return 0;
}
