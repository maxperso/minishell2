/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strrchr.c
*/

#include "../../include/my.h"

char *my_strrchr(char *str, int c)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            count = i;
    return (str + count);
}
