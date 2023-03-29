/*
** EPITECH PROJECT, 2022
** dante
** File description:
** recursive.c
*/

#include "../inc/generator.h"

int get_random(int min, int max, char even)
{
    int true_min = min;
    if (even && min % 2 || !even && min % 2 == 0)
        true_min += 1;
    return (rand() % (max - true_min + 1)) / 2 * 2 + true_min;
}

void cut_vertical(char **maze, maze_t *coords, char perfect)
{
    int cut = get_random(coords->x, coords->x + coords->width - 1, 0);
    int hole = get_random(coords->y, coords->y + coords->height - 1, 1);
    maze_t left_coords = {coords->x, coords->y, cut - coords->x,
    coords->height};
    maze_t right_coords = {cut + 1, coords->y, coords->width -
    (cut - coords->x + 1), coords->height};

    for (int y = coords->y; y < coords->y + coords->height; y++) {
        if (y == hole)
            continue;
        maze[y][cut] = 'X';
    }
    cut_in_half(maze, &left_coords, perfect);
    cut_in_half(maze, &right_coords, perfect);
}

void cut_horizontal(char **maze, maze_t *coords, char perfect)
{
    int cut = get_random(coords->y, coords->y + coords->height - 1, 0);
    int hole = get_random(coords->x, coords->x + coords->width - 1, 1);
    maze_t up_coords = { coords->x, coords->y, coords->width, cut - coords->y };
    maze_t down_coords = { coords->x , cut + 1, coords->width, coords->height -
    (cut - coords->y + 1) };

    memset(maze[cut] + coords->x, 'X', coords->width);
    maze[cut][hole] = '*';
    cut_in_half(maze, &up_coords, perfect);
    cut_in_half(maze, &down_coords, perfect);
}

void cut_in_half(char **db, maze_t *coords, char perfect)
{
    if (coords->width < (perfect ? 2 : 4) || coords->height < (perfect ? 2 : 4))
        return;
    if (coords->width > coords->height)
        cut_vertical(db, coords, perfect);
    else
        cut_horizontal(db, coords, perfect);
}

char **create_maze(int width, int height, char perfect)
{
    char **db = malloc(sizeof(char *) * height);
    maze_t coords = { 0, 0, width, height };
    int end;

    for (int i = 0; i < height; i++) {
        db[i] = malloc(sizeof(char) * width);
        memset(db[i], '*', width);
    }
    if (width % 2 == 0 && height % 2 == 0) {
        memset(db[height - 1], 'X', width);
        coords.height--;
    }
    cut_in_half(db, &coords, perfect);
    if (width % 2 == 0 && height % 2 == 0) {
        for (end = width - 1; end > 0 && db[height - 2][end] != '*'; end--)
            db[height - 1][end] = '*';
        db[height - 1][end] = '*';
    }
    return db;
}
