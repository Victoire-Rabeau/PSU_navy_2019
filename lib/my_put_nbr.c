/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Displays a number
*/

#include<unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb  = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else my_putchar ('0' + nb);
    return (nb);
}
