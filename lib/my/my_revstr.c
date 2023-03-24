/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse string
*/

#include "../../include/my.h"

void my_revstr(char *str)
{
    int len = 0;
    char swap;

    for (; str[len]; len++);
    len--;
    for (int i = 0; i <= len; i++, len--) {
        swap = str[i];
        str[i] = str[len];
        str[len] = swap;
    }
}
