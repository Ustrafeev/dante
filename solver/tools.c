/*
** EPITECH PROJECT, 2022
** solver
** File description:
** tools.c
*/

#include "inc/solver.h"

void place_x(t_coords *pos, t_solver *maze)
{
    maze->cheat_map[pos->y][pos->x] = 'a';
    return;
}

int v_exist_in_open(t_node *open, t_node *v)
{
    t_node *temp = open;
    while (temp) {
        if (temp->pos->x == v->pos->x && temp->pos->y == v->pos->y &&
        temp->math->f_cost <= v->math->f_cost)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int v_in_closed(t_node *closed, t_node *v)
{
    if (closed == NULL)
        return 0;
    t_node *temp = closed;
    while (temp) {
        if (temp->pos->x == v->pos->x && temp->pos->y == v->pos->y)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void display_coords(t_node *list)
{
    t_node *temp = list;
    while (temp) {
        mini_printf("id = %i, parent = %i, [%i][%i]\n", temp->id,
        temp->parent_id, temp->pos->y, temp->pos->x);
        temp = temp->next;
    }
    mini_printf("\n");
}

void display_list(t_node *list)
{
    t_node *temp = list;
    while (temp) {
        mini_printf(" %i - ", temp->math->f_cost);
        temp = temp->next;
    }
    mini_printf("\n");
}
