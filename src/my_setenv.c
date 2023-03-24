/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_setenv.c
*/

#include "../include/my_proj.h"

char **add_to_env(char **env, int add, char *to_add)
{
    char **new_env = malloc(sizeof(char *) * size_env(env) + 1 + add);
    int c = 0, i = 0;
    for (; env[c]; c++) {
        if (env[c][0] == '?')
            continue;
        new_env[i] = my_strdup(env[c]);
        i++;
    }
    if (to_add != NULL && add == 1)
        new_env[i] = my_strdup(to_add);
    free_array(env);
    return (new_env);
}

int get_start(char *str)
{
    int start = 0;

    for (; is_alpha(str[start]) == 0; start++);
    return (start);
}

void my_setenv(arg_t *arg)
{
    return;
    char *var = my_strdup_from(arg->cmd, 7);
    char *value = my_strdup_fromtonb(arg->cmd, my_strlen(var) + 8);
    var = my_strcat_mal(var, "=");
    var = my_strcat_mal(var, value);
    my_putstr(var);
    for (int i = 0; arg->env[i]; i++)
        if (my_strncmp(arg->cmd, arg->env[i], my_strlen(arg->cmd)
        - my_strlen(var)) == 0) {
            arg->env[i] = my_strdup(var);
            return;
        }
    arg->env = add_to_env(arg->env, 1, var);
}

void my_unsetenv(arg_t *arg)
{
    return;
    char *var = my_strdup_from(arg->cmd, 9);
    for (int i = 0; arg->env[i]; i++)
        if (my_strncmp(var, arg->env[i], my_strlen(var) - 1) == 0) {
            arg->env[i][0] = '?';
            arg->env = add_to_env(arg->env, 0, NULL);
        }
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
