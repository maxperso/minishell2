/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int c = 0;
    int i = 0;

    for (; src[c]; c++);
    char *str = malloc(sizeof(char) * (c + 1));
    for (; src[i]; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}

char *my_strdup_from(char const *src, int start)
{
    int c = start, i = 0;
    char *str;

    for (; src[c]; c++);
    str = (char *)malloc(sizeof(char) * (c + 1));
    for (; src[start] && src[start] != ' '; start++, i++) {
        str[i] = src[start];
    }
    str[i] = '\0';
    return (str);
}

char *my_strdup_fromtonb(char const *src, int start)
{
    int c = start, i = 0;
    char *str = NULL;

    for (; src[c]; c++);
    str = (char *)malloc(sizeof(char) * (c + 1));
    for (; src[start] && is_alphanum(src[start]) == 0; start++, i++)
        str[i] = src[start];
    str[i] = '\0';
    return (str);
}
