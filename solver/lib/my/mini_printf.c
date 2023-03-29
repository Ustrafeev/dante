/*
** EPITECH PROJECT, 2022
** miniprintf
** File description:
** mini_printf.c
*/

#include "../../inc/lib.h"

int manage_flag(const char *format, va_list list, int i, int count)
{
    switch (format[i + 1]) {
        case 'c': my_putchar(va_arg(list, int));
            count++;
        break;
        case 'd': case 'i': int nb = va_arg(list, int);
            count += my_put_nbr(nb);
        break;
        case 's': char *strx = va_arg(list, char *);
            my_putstr(strx);
            count += my_strlen(strx);
        break;
        case '%': my_putchar('%');
            count++;
        break;
        default: my_putchar(format[i--]);
            count++;
        break;
        }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    va_start(list, format);
    int count = 0;

    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            count++;
        } else {
            count = manage_flag(format, list, i, count);
            i++;
        }
    }
    va_end(list);
    return count;
}
