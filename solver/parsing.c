/*
** EPITECH PROJECT, 2022
** solver
** File description:
** parsing.c
*/

#include "inc/solver.h"

char *file_wo_errors(char *adress)
{
    char *str = get_str_from_file(adress);
    return str;
}

int get_nb_lines(char *file_str)
{
    int count = 0;

    for (int i = 0; file_str[i] != '\0'; i++)
        count += (file_str[i] == '\n') ? 1 : 0;
    return count;
}

char **str_to_tab(char *file_str, int nb_lines)
{
    char *content = strdup(file_str);
    char *delims = "\n";
    char *line = strtok(content, delims);
    char **tab = malloc(sizeof(char *) * (nb_lines + 1));

    for (int i = 0; line; i++) {
        tab[i] = line;
        line = strtok(NULL, delims);
    }
    tab[nb_lines] = NULL;
    return tab;
}
