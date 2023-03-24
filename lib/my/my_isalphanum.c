/*
** EPITECH PROJECT, 2022
** is_alphanum.c
** File description:
** is alpha
*/

#include "../../include/my.h"

int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
    (c >= 45 && c <= 63) || (c == 124))
        return (0);
    return (1);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}
