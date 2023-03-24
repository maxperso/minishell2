/*
** EPITECH PROJECT, 2022
** my_PROJ.h
** File description:
** MY_PROJ_
*/

#ifndef MY_LS_
    #define MY_LS_

    /* INCLUDE */
    #include "my.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <pwd.h>
    #include <dirent.h>
    #include <grp.h>
    #include <time.h>
    #include <signal.h>
    #include <limits.h>
    #include <fcntl.h>

    /* STRUCTS */
    typedef struct list_t {
        char *data;
        struct list *next;
    } list_t, *list;

    typedef struct arg_t {
        char *cmd;
        char **args;
        char *buffer;
        char **env;
        char *filename;
        char *temp;
        int redir_nbr;
        int arg_nbr;
        int i;
        int nbr;
        int redir;
        int separ;
        int et;
        int point_vir;
        int pipe;
        int d_pipe;
    } arg_t;

    /* MAIN FUNCTIONS */
    char **get_env(char **env);
    int size_env(char **env);
    char **get_arg(int ac, char **av);
    int launch_shell(int ac, char **av, char **env, arg_t *arg);
    void init_struct(arg_t *arg);
    char *good_bin(char *str);
    char *trim_str(char *str);
    void free_array(char **array);
    /* BUILTINS */
    int is_built_in(char *str, arg_t *arg);
    void built_in_cd(arg_t *arg);
    void change_pwd(arg_t *arg);
    void built_in_env(arg_t *arg);
    void built_in_pwd(arg_t *arg);
    void my_setenv(arg_t *arg);
    void my_unsetenv(arg_t *arg);
    void built_in_exit(arg_t *arg);
    /* REDIRECTIONS */
    int if_separator(char c);
    void output_redir(arg_t *arg);
    void input_redir(arg_t *arg);
    void d_output_redir(arg_t *arg);
    void d_input_redir(arg_t *arg);
    void choose_redir(arg_t *arg, char *trimed_str);
    void filename_redir(char *str, int i, arg_t *arg);
    /* SEPARATORS */
    void choose_separator(arg_t *arg, char *trimed_str);
    void check_separator(arg_t *arg, char *trimed_str);
    int pipe_process(arg_t *arg);
    void count_sep(arg_t *arg, char *trimed_str);
    char *parsing_sep(char *trimed_str, arg_t *arg);
    int if_separ(char c);
    void nbr_of_sep(arg_t *arg);

#endif /* !MY_PROJ_ */
