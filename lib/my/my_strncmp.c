/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strncmp.c
*/

#include "../../include/my.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    for (; i != n && (s1[i] == s2[i]) && s1[i] && s2[i]; i++);
    if (i == n)
        return (0);
    if (s1[i] > s2[i])
        return (s2[i] - s1[i]);
    else
        return (s1[i] - s2[i]);
}
