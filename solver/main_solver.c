/*
** EPITECH PROJECT, 2022
** dante
** File description:
** main_solver.c
*/

#include "inc/solver.h"

void reconstruct_the_way(t_solver *maze)
{
    t_node *temp = maze->closed;
    int x = temp->pos->x;
    int y = temp->pos->y;
    maze->maze[y][x] = 'o';
    while (temp->id != 0) {
        int goal = temp->parent_id;
        while (temp->id != goal)
            temp = temp->next;
        x = temp->pos->x;
        y = temp->pos->y;
        maze->maze[y][x] = 'o';
    }
    for (int i = 0; maze->maze[i]; i++) {
        write(1, maze->maze[i], maze->finish->x + 1);
        if (i < maze->finish->y)
            write(1, "\n", 1);
    }
    exit(0);
}

t_node *add_v_node(t_node *u, t_solver *maze, t_coords *new_pos, int id)
{
    if (new_pos->y < 0 || new_pos->y > maze->finish->y || new_pos->x < 0 ||
    new_pos->x > maze->finish->x)
        return maze->open;
    if (maze->maze[new_pos->y][new_pos->x] == '*') {
        if (maze->cheat_map[new_pos->y][new_pos->x] != 'a') {
            place_x(new_pos, maze);
            t_node *v = malloc(sizeof(t_node));
            v->pos = malloc(sizeof(t_coords));
            v->pos->y = new_pos->y;
            v->pos->x = new_pos->x;
            v->math = malloc(sizeof(t_stat));
            v->math->h_cost = calc_h(maze->finish, v->pos);
            v->math->g_cost = u->math->g_cost + 1;
            v->math->f_cost = v->math->g_cost + v->math->h_cost;
            v->parent_id = u->id;
            v->id = id;
            maze->open = add_to_sort_open(v, maze->open);
        }
    }
    return maze->open;
}

t_node *add_possible_ways(t_node *u, int id, t_solver *maze)
{
    t_coords *v = malloc(sizeof(t_coords));
    v->y = u->pos->y - 1;
    v->x = u->pos->x;
    maze->open = add_v_node(u, maze, v, id++);
    v->y = u->pos->y + 1;
    maze->open = add_v_node(u, maze, v, id++);
    v->y = u->pos->y;
    v->x = u->pos->x + 1;
    maze->open = add_v_node(u, maze, v, id++);
    v->x = u->pos->x - 1;
    maze->open = add_v_node(u, maze, v, id++);
    return maze->open;
}

void main_loop(t_solver *maze)
{
    int id = 1;
    while (maze->open) {
        t_node *u = depop_from_open(maze->open);
        maze->open = depop_cut(maze->open);
        if (u->pos->x == maze->finish->x && u->pos->y == maze->finish->y) {
            maze->closed = add_to_closed(u, maze->closed);
            reconstruct_the_way(maze);
        }
        maze->open = add_possible_ways(u, id, maze);
        id += 4;
        maze->closed = add_to_closed(u, maze->closed);
    }
    mini_printf("no solution found");
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    char *file_str = get_str_from_file(argv[1]);
    if (file_str == NULL)
        return 84;
    t_solver *maze = init_maze(file_str);
    main_loop(maze);
    return 0;
}
