/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** concate string
*/

#include "../../include/my.h"

char *my_strcat_mal(char *dest, const char *src)
{
    int size_dest = dest ? my_strlen(dest) : 0;
    int size_src = src ? my_strlen(src) : 0;
    int size = size_dest + size_src;
    char *new_str = malloc(sizeof(char) * size + 1);
    int i = 0, a = 0;

    for (i; i < size; i++) {
        if (i < size_dest)
            new_str[i] = dest[i];
        if (i >= size_dest) {
            new_str[i] = src[a];
            a++;
        }
    }
    new_str[i] = '\0';
    return (new_str);
}
