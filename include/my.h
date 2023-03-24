/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** MY_H_
*/

#ifndef MY_H_
    #define MY_H_

    /* INCLUDE */
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stddef.h>

    /* LIB */
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_put_nbr_long_long(long long n);
    int my_strlen(char const *str);
    void my_revstr(char *str);
    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(const char *str1, const char *str2);
    char *my_strcat_mal(char *dest, const char *src);
    char **my_str_to_word_array(char *str, char separator);
    int is_alphanum(char c);
    int is_alpha(char c);
    int is_num(char c);
    char *my_strdup_from(char const *src, int start);
    char *my_strdup_fromtonb(char const *src, int start);
    char *my_strdup(char const *src);
    int my_strncmp(char *s1, char *s2, int n);
    char *my_strrchr(char *str, int c);

#endif /* !MY_H_ */
