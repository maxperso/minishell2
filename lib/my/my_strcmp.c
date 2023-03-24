/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** str compare
*/

#include "../../include/my.h"

int my_strcmp(const char *str1, const char *str2)
{
    int len = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len != len2)
        return (2);
    for (int i = 0; i < len; i++) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}
