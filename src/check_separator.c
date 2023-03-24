/*
** EPITECH PROJECT, 2022
** check_separator.c
** File description:
** check if input contain separator
*/

#include "../include/my_proj.h"

int if_separator(char c)
{
    if (c == '|' || c == '&' || c == ';')
        return (1);
    return (0);
}

void filename_redir(char *str, int i, arg_t *arg)
{
    arg->filename = malloc(sizeof(char) * my_strlen(str));
    int a = 0;

    for (i = i + 1; str[i] != '\0'; i++) {
        if (str[i] != ' '){
            arg->filename[a] = str[i];
            a++;
        }
        arg->filename[a] = '\0';
    }
}

void choose_separator(arg_t *arg, char *trimed_str)
{
    for (int i = 0; trimed_str[i] != '\0'; i++) {
        if ((trimed_str[i] == '>') || (trimed_str[i] == '<') ||
        (trimed_str[i] == '>' && trimed_str[i + 1] == '>') ||
        (trimed_str[i] == '<' && trimed_str[i + 1] == '<'))
            arg->redir = 1;
    }
}

void check_separator(arg_t *arg, char *trimed_str)
{
    init_struct(arg);

    for (int i = 0; trimed_str[i] != '\0'; i++) {
        if ((trimed_str[i] == '>') || (trimed_str[i] == '<') ||
        (trimed_str[i] == '>' && trimed_str[i + 1] == '>') ||
        (trimed_str[i] == '<' && trimed_str[i + 1] == '<') ||
        (trimed_str[i] == '&' && trimed_str[i + 1] == '&') ||
        (trimed_str[i] == '|' && trimed_str[i + 1] == '|') ||
        (trimed_str[i] == ';') || (trimed_str[i] == '|')) {
            arg->separ = 1;
        }
    }
}

void choose_redir(arg_t *arg, char *trimed_str)
{
    for (int i = 0; trimed_str[i] != '\0' &&
    if_separator(trimed_str[i]) == 0; i++) {
        if (trimed_str[i] == '>') {
            filename_redir(trimed_str, i, arg);
            output_redir(arg);
        }
        if (trimed_str[i] == '>' && trimed_str[i + 1] == '>')
            d_output_redir(arg);
        if (trimed_str[i] == '<')
            input_redir(arg);
        if (trimed_str[i] == '<' && trimed_str[i + 1] == '<')
            d_input_redir(arg);
    }
}
