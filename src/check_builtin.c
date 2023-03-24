/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** check_builtin.c
*/

#include "../include/my_proj.h"

int is_built_in(char *str, arg_t *arg)
{
    void (*handler[])(arg_t *) = {built_in_pwd, built_in_cd, built_in_env,
    my_setenv, my_unsetenv, built_in_exit, NULL};
    char *builtin[] = {"pwd", "cd", "env", "setenv", "unsetenv", "exit", NULL};
    for (int i = 0; builtin[i]; i++)
        if (my_strncmp(str, builtin[i], my_strlen(builtin[i])) == 0) {
            handler[i](arg);
            return (0);
        }
    return (1);
}
