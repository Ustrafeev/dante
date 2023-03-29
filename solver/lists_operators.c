/*
** EPITECH PROJECT, 2022
** solver
** File description:
** lists_operators.c
*/

#include "inc/solver.h"

t_node *add_to_closed(t_node *new, t_node *closed)
{
    if (closed == NULL)
        return new;
    new->next = closed;
    closed->previous = new;
    new->previous = NULL;
    closed = new;
    return closed;
}

t_node *depop_from_open(t_node *open_list)
{
    t_node *temp = malloc(sizeof(t_node));
    temp->next = NULL;
    temp->math = open_list->math;
    temp->pos = open_list->pos;
    temp->previous = NULL;
    temp->id = open_list->id;
    temp->parent_id = open_list->parent_id;
    return temp;
}

t_node *depop_cut(t_node *open_list)
{
    open_list = open_list->next;
    if (open_list)
        open_list->previous = NULL;
    return open_list;
}

t_node *add_to_sort_help(t_node *temp, int f, t_node *open_list, t_node *new)
{
    while (temp->next && temp->next->math->f_cost < f)
        temp = temp->next;
    if (temp->next == NULL) {
        temp->next = new;
        new->previous = temp;
        new->next = NULL;
        return open_list;
    } else {
        t_node *temp_next = temp->next;
        temp_next->previous = new;
        new->next = temp_next;
        temp->next = new;
        new->previous = temp;
        temp;
        return open_list;
    }
}

t_node *add_to_sort_open(t_node *new, t_node *open_list)
{
    int f = new->math->f_cost;
    t_node *temp = open_list;
    if (!open_list) {
        new->next = NULL;
        new->previous = NULL;
        return new;
    }
    if (f <= open_list->math->f_cost) {
        new->next = open_list;
        open_list->previous = new;
        new->previous = NULL;
        open_list = new;
        return open_list;
    }
    return add_to_sort_help(temp, f, open_list, new);
}
