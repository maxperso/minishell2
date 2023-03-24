/*
** EPITECH PROJECT, 2022
** trim_str.c
** File description:
** trim string
*/

#include "../include/my_proj.h"

char *clean_start(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    int a = 0;
    int cpt = 0;

    for (i; str[i] != '\0' && is_alphanum(str[i]) == 1; i++)
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            cpt++;
    for (i = cpt; str[i] != '\0'; i++) {
        new_str[a] = str[i];
        a++;
    }
    new_str[a] = '\0';
    free(str);
    return (new_str);
}

char *clean_end(char *str)
{
    my_revstr(str);
    str = clean_start(str);
    my_revstr(str);
    return (str);
}

int rm_space(char *str, int i)
{
    while (str[i] == ' ')
        i++;
    return (i);
}

char *second_trim(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i = rm_space(str, i);
            new_str[a] = ' ';
            a++;
        }
        new_str[a] = str[i];
        a++;
    }
    new_str[a] = '\0';
    free(str);
    return (new_str);
}

char *trim_str(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    int a = 0;

    for (int i = 0; str[i]; i++, a++) {
        if (str[i] == '\t' || str[i] == '\n') i++;
        if (!str[i]) break;
        if (!str[i + 1] && is_alphanum(str[i]) == 1) {
            new_str[a] = str[i];
            continue;
        }
        if (str[i] == ' ' && (str[i + 1] < 'a' || str[i + 1] > 'z') &&
        (str[i + 1] < 'A' || str[i + 1] > 'Z') && (str[i + 1] < 33 ||
        str[i + 1] > 63) && (str[i + 1] < 123 || str[i + 1] > 126)) i++;
        new_str[a] = str[i];
    }
    new_str[a] = '\0', new_str = clean_start(new_str);
    new_str = clean_end(new_str);
    return (second_trim(new_str));
}
