/*
** EPITECH PROJECT, 2022
** get_arg.c
** File description:
** get args
*/

#include "../include/my_proj.h"

char *good_bin(char *str)
{
    char *bin;

    bin = my_strcat_mal("/bin/", str);
    return (bin);
}

char **get_arg(int ac, char **av)
{
    char **tab = malloc(sizeof(char *) * ac);
    int i = 0;

    for (i; i < ac; i++) {
        tab[i] = malloc(sizeof(char) * my_strlen(av[i]));
        for (int a = 0; av[i][a] != '\0'; a++) {
            tab[i][a] = av[i][a];
        }
    }
    tab[i] = NULL;
    return (tab);
}
