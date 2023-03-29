/*
** EPITECH PROJECT, 2022
** dante
** File description:
** solver.h
*/

#pragma once

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"

typedef struct s_coords {
    int x;
    int y;
} t_coords;

typedef struct s_stat {
    int f_cost;
    int h_cost;
    int g_cost;
} t_stat;

typedef struct s_node {
    t_coords *pos;
    struct s_node *next;
    struct s_node *previous;
    t_stat *math;
    int id;
    int parent_id;
} t_node;


typedef struct s_solver {
    char **maze;
    t_coords *finish;
    t_node *closed;
    t_node *open;
    char **cheat_map;
} t_solver;

char *file_wo_errors(char *adress);
t_solver *init_maze(char *file_str);
int get_nb_lines(char *file_str);
char **str_to_tab(char *file_str, int nb_lines);
int calc_h(t_coords *dest, t_coords *current);
t_node *add_to_closed(t_node *new, t_node *closed);
t_node *depop_from_open(t_node *open_list);
t_node *depop_cut(t_node *open_list);
t_node *add_to_sort_open(t_node *new, t_node *open_list);
int v_exist_in_open(t_node *open, t_node *v);
int v_in_closed(t_node *closed, t_node *v);
void display_coords(t_node *list);
void display_list(t_node *list);
void place_x(t_coords *pos, t_solver *maze);
