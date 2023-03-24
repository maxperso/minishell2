/*
** EPITECH PROJECT, 2022
** count_sep.c
** File description:
** Function for count sepatators
*/

#include "../include/my_proj.h"

int if_separ(char c)
{
    if ((c == ';') || (c == '>'))
        return (1);
    return (0);
}

void nbr_of_sep(arg_t *arg)
{
    arg->arg_nbr = 0;
    arg->arg_nbr = arg->pipe + arg->point_vir;
}

char *parsing_sep(char *trimed_str, arg_t *arg)
{
    char *new_str = malloc(sizeof(char) * my_strlen(trimed_str) + 1);
    int a = 0;

    for (arg->i; if_separ(trimed_str[arg->i]) == 0 &&
    trimed_str[arg->i] != '\0'; arg->i++) {
        new_str[a] = trimed_str[arg->i];
        a++;
    }
    new_str[a] = '\0';
    arg->i++;
    return (new_str);
}

void count_sep(arg_t *arg, char *trimed_str)
{
    init_struct(arg);

    for (int i = 0; trimed_str[i] != '\0'; i++) {
        if ((trimed_str[i] == '>' && trimed_str[i + 1] == ' ' &&
        trimed_str[i - 1] == ' ') || (trimed_str[i] == '<' &&
        trimed_str[i + 1] == ' ' && trimed_str[i - 1] == ' ') ||
        (trimed_str[i] == '>' && trimed_str[i + 1] == '>') ||
        (trimed_str[i] == '<' && trimed_str[i + 1] == '<'))
            arg->redir_nbr++;
        if (trimed_str[i] == '&' && trimed_str[i + 1] == '&')
            arg->et++;
        if (trimed_str[i] == '|' && trimed_str[i + 1] == '|')
            arg->d_pipe++;
        if (trimed_str[i] == '|')
            arg->pipe++;
        if (trimed_str[i] == ';')
            arg->point_vir++;
    }
}
