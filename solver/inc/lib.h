/*
** EPITECH PROJECT, 2022
** B-MAT-100-LYN-1-1-101pong-irina.ustrafeeva
** File description:
** my_h.h
*/

#ifndef MAIN_H
    #define MAIN_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #define ABS(value) ((value > 0) ? value : -(value))

    int my_put_nbr(int nb);
    int my_put_nbr_unsigned(unsigned int nb, int len);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int mini_printf(const char *format, ...);
    char *get_str_from_file(char *address);

#endif /* MAIN_H */
