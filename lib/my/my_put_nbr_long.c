/*
** EPITECH PROJECT, 2022
** my_put_nbr_long.c
** File description:
** put nbr for long int
*/

#include "../../include/my.h"

int my_put_nbr_long_long(long long n)
{
    if (n < 0) {
        my_putchar('-');
        my_putstr("-2147483648");
    }
    if (n > 9) {
        my_put_nbr_long_long(n / 10);
        my_put_nbr_long_long(n % 10);
    } else
        my_putchar(n + '0');

    return (0);
}
