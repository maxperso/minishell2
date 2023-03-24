/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** pipes.c
*/

#include "../include/my_proj.h"

int size_tab(char ***tab)
{
    int count = 0;
    for (int i = 0; tab[i]; i++)
        count++;
    return (count);
}

int count_tab(char **tab)
{
    int count = 0;
    for (int i = 0; tab[i]; i++)
        count++;
    return (count);
}

char ***pipe_tab(char **tab, arg_t *arg)
{
    char ***new_tab = malloc(sizeof(char **) * (arg->pipe + 2));
    int i = 0, j = 0, c = 0;

    for (int i = 0; tab[j] && i < arg->pipe + 1; i++, j++) {
        new_tab[i] = malloc(sizeof(char *) * (count_tab(tab) + 1));
        for (c = 0; tab[j] && tab[j][0] != '|'; j++, c++)
            new_tab[i][c] = my_strdup(tab[j]);
        new_tab[i][c] = NULL;
        if (!tab[j]) {
            break;
        }
    }
    return (new_tab);
}

int process(int in, int out, char **tab)
{
    pid_t pid;

    if ((pid = fork() == 0)) {
        if (in != 0) {
            dup2(in, 0);
            close(in);
        }
        if (out != 1) {
            dup2(out, 1);
            close(out);
        }
        execve(good_bin(tab[0]), tab, NULL);
    }
    return (pid);
}

int pipe_process(arg_t *arg)
{
    char ***tab = pipe_tab(arg->args, arg);
    int fd[2], in = 0, i = 0, n = 0, status = 0;
    pid_t pid;

    if (pipe(fd) != 0) return (84);
    if (fork() == 0) {
        dup2(fd[1], 1);
        close(fd[0]), close(fd[1]);
        execve(good_bin(tab[i][0]), tab[i], NULL);
    }
    if (fork() == 0) {
        dup2(fd[0], 0);
        close(fd[0]), close(fd[1]);
        execve(good_bin(tab[i + 1][0]), tab[i + 1], NULL);
    }
    close(fd[0]), close(fd[1]);
    wait(NULL);
    wait(NULL);
    return (0);
}
