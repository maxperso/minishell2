/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** builtin.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>
#include "../include/my_proj.h"

void built_in_pwd(arg_t *arg)
{
    char *cwd = (char *)malloc(sizeof(char) * PATH_MAX + 1);

    if (getcwd(cwd, PATH_MAX + 1) != NULL) my_putstr(cwd), my_putchar('\n');
    else
        perror("getcwd()\n");
}

void change_pwd(arg_t *arg)
{
    int i = 0, pwd = 0, opwd = 0;
    char *old_pwd = NULL;

    while (arg->env[i++]) {
        if (my_strlen(arg->env[i]) > 5 &&
        my_strncmp(arg->env[i], "PWD=", 4) == 0)
            pwd = i;
        if (my_strlen(arg->env[i]) > 8 &&
        my_strncmp(arg->env[i], "OLDPWD=", 7) == 0)
            opwd = i;
        if (pwd != 0 && opwd != 0)
            break;
    }
    arg->env[opwd] = my_strcat_mal("OLDPWD=",
    my_strdup_from(arg->env[pwd], 4));
    arg->env[pwd] = my_strcat_mal("PWD=", arg->cmd);

}

void built_in_cd(arg_t *arg)
{
    char *path = my_strdup_from(arg->cmd, 3);
    int ch = 0;
    if (path[0] == '-' && path[1] == '-' || !path) {
        for (int i = 0; arg->env[i]; i++)
            my_strncmp(arg->env[i], "OLDPWD=", 7) == 0 ? path =
            my_strdup_from(arg->env[i], 8) : 0;
    }
    if (ch = chdir(path) == -1) {
        path = my_strcat_mal(path, ": Not a directory.\n");
        write(2, path, my_strlen(path));
        free(path);
        return;
    }
    free(path);
}

void built_in_env(arg_t *arg)
{
    for (int i = 0; arg->env[i]; i++) {
        my_putstr(arg->env[i]);
        my_putchar('\n');
    }
}

void built_in_exit(arg_t *arg)
{
    if (my_strcmp(arg->cmd, "exitt") == 0)
        (write(2, "exitt: Command not found.\n", 27));
    else {
        free(arg->env);
        exit(0);
    }
}
