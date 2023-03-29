/*
** EPITECH PROJECT, 2022
** solver
** File description:
** init.c
*/

#include "inc/solver.h"

t_node *init_open(void)
{
    t_node *res = malloc(sizeof(t_node));
    res->math = malloc(sizeof(t_stat));
    res->math->f_cost = 0;
    res->math->g_cost = 0;
    res->math->h_cost = 0;
    res->pos = malloc(sizeof(t_coords));
    res->pos->x = 0;
    res->pos->y = 0;
    res->next = NULL;
    res->previous = NULL;
    res->id = 0;
    return res;
}

void error_check(t_solver *maze)
{
    int ideal = my_strlen(maze->maze[0]);
    for (int i = 0; maze->maze[i]; i++) {
        if (my_strlen(maze->maze[i]) != ideal) {
            mini_printf("no solution found");
            exit(84);
        }
    }
    if (maze->maze[0][0] == 'X' || maze->maze[maze->finish->y][maze->finish->x]
    == 'X') {
        mini_printf("no solution found");
        exit(84);
    }
}

t_solver *init_maze(char *file_str)
{
    t_solver *res = malloc(sizeof(t_solver));
    res->finish = malloc(sizeof(t_coords));
    res->finish->y = get_nb_lines(file_str);
    res->maze = str_to_tab(file_str, res->finish->y + 1);
    res->finish->x = my_strlen(res->maze[0]) - 1;
    res->open = init_open();
    res->closed = NULL;
    res->cheat_map = str_to_tab(file_str, res->finish->y + 1);
    error_check(res);
    return res;
}
