/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "../include/my_proj.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    arg_t *arg = malloc(sizeof(arg_t));
    init_struct(arg);
    launch_shell(ac, av, env, arg);
    return (0);
}
