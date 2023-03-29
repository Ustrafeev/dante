/*
** EPITECH PROJECT, 2022
** dante
** File description:
** display.c
*/

#include "../inc/generator.h"

void show_maze(char **maze, int width, int height)
{
    for (int y = 0; y < height; y++) {
        write(1, maze[y], width);
        if (y != height - 1)
            my_putchar('\n');
    }
}
