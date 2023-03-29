/*
** EPITECH PROJECT, 2022
** solver
** File description:
** file_to_str.c
*/

#include "../../inc/lib.h"

char *get_str_from_file(char *address)
{
    int fd = open(address, O_RDONLY);
    struct stat file;
    stat(address, &file);
    int size = file.st_size;
    char *buff = malloc(sizeof(char) * size + 1);

    read(fd, buff, size);
    close(fd);
    buff[size] = '\0';
    if (buff[size] == '\n') {
        mini_printf("no solution found");
        exit(0);
    }
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != '*' && buff[i] != 'X' && buff[i] != '\n')
            exit(84);
    }
    return buff;
}
