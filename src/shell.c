/*
** EPITECH PROJECT, 2022
** shell.c
** File description:
** shell start
*/

#include "../include/my_proj.h"

int manage_separator(arg_t *arg, char *trimed_str)
{
    int c = 0;

    check_separator(arg, trimed_str);
    if (arg->separ == 1)
        choose_separator(arg, trimed_str), c = 1;
    if (arg->redir == 1)
        choose_redir(arg, trimed_str), c = 1;
    if (arg->pipe == 1)
        pipe_process(arg);
    return (c);
}

void current_dir(void)
{
    char *new_current = malloc(sizeof(char) * my_strlen(getcwd(NULL, 0)));
    char *current = (getcwd(NULL, 0));
    int i = 0;

    my_revstr(current);
    for (; current[i] != '/'; i++)
        new_current[i] = current[i];
    new_current[i] = '\0';
    my_revstr(new_current);
    my_putstr("\e[1;96m");
    my_putstr(new_current);
    my_putstr("\033[0;34m");
    my_putstr(":> ");
    my_putstr("\e[0;00m");
}

int take_arg(arg_t *arg, char **env, int ac, char **av)
{
    int w = 0;
    char *basic_str = trim_str(arg->buffer);
    char *str_trimed = trim_str(arg->temp);
    arg->cmd = trim_str(arg->buffer);
    arg->args = my_str_to_word_array(str_trimed, ' ');
    char *bin = my_strncmp(arg->args[0], "/bin/", 5) == 0 ? arg->args[0] :
    good_bin(arg->args[0]);
    if (is_built_in(arg->cmd, arg) == 0)
        return (0);
    if (fork() == 0) {
        if (arg->redir == 1)
            choose_redir(arg, basic_str);
        execve(bin, arg->args, arg->env);
    } else
        wait(&w);
    return (0);
}

int call_shell(arg_t *arg, char **env, int ac, char **av)
{
    int cpt = 0;
    char *str_trimed = trim_str(arg->buffer);
    arg->args = my_str_to_word_array(str_trimed, ' ');
    count_sep(arg, str_trimed);
    nbr_of_sep(arg);
    choose_separator(arg, str_trimed);

    if (arg->redir == 1) {
        arg->temp = parsing_sep(str_trimed, arg);
        take_arg(arg, env, ac, av);
        return (0);
    }
    if (arg->pipe != 0)
        return (pipe_process(arg));
    while (cpt < arg->point_vir + 1) {
        arg->temp = parsing_sep(trim_str(arg->buffer), arg);
        take_arg(arg, env, ac, av);
        cpt++;
    }
    return (0);
}

int launch_shell(int ac, char **av, char **env, arg_t *arg)
{
    size_t buffsize = 0;
    arg->env = get_env(env);
    arg->buffer = NULL;

    while (1) {
        current_dir();
        if (getline(&arg->buffer, &buffsize, stdin) == -1)
            return (84);
        call_shell(arg, env, ac, av);
        free(arg->buffer);
        arg->buffer = NULL;
        buffsize = 0;
    }
    return (0);
}
