/*
** EPITECH PROJECT, 2022
** solver
** File description:
** math.c
*/

#include "inc/solver.h"

int calc_h(t_coords *dest, t_coords *current)
{
    return (abs(dest->x - current->x) + abs(dest->y - current->x));
}
