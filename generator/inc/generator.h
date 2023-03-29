/*
** EPITECH PROJECT, 2022
** dante
** File description:
** generator.h
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct maze {
    int x;
    int y;
    int width;
    int height;
}maze_t;

//lib
int my_putchar(char c);
int is_num(char *str);

//error_management
int error_handling(int argc, char **argv);

void show_maze(char **maze, int width, int height);
char **create_maze(int width, int height, char perfect);
void cut_in_half(char **db, maze_t *coords, char perfect);
void show_maze(char **maze, int width, int height);
