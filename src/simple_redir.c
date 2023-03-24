/*
** EPITECH PROJECT, 2022
** simple_redir.c
** File description:
** simple redirection
*/

#include "../include/my_proj.h"

void output_redir(arg_t *arg)
{
    int fd = open(arg->filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
    dup2(fd, STDOUT_FILENO);
}

void input_redir(arg_t *arg)
{

}
