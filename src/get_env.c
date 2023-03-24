/*
** EPITECH PROJECT, 2022
** get_env.c
** File description:
** get env
*/

#include "../include/my_proj.h"

int size_env(char **env)
{
    int cpt = 0;

    for (int i = 0; env[i] != NULL; i++)
        cpt++;
    return (cpt);
}

char **get_env(char **env)
{
    int x = 0;
    char **new_env = malloc(sizeof(char *) * (size_env(env) + 1));

    for (; env[x]; x++)
        new_env[x] = my_strdup(env[x]);
    new_env[x] = NULL;
    return (new_env);
}
