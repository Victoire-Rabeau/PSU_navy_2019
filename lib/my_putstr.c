/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Displays one by one the characters of a string
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}
