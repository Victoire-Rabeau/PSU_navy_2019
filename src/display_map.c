/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** display_map
*/

#include "navy.h"
#include "my.h"

void display_map(char **map)
{
    int j = 0;

    my_putstr(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putstr("|");
        j = 0;
        for (; j < 7; j++) {
            my_putchar(map[i][j]);
            my_putchar(' ');
        }
        my_putchar(map[i][j]);
        my_putstr("\n");
    }
    my_putstr("\n");
}

void display_both_maps(game_t *game)
{
    my_putstr("my positions:\n");
    display_map(game->map_player);
    my_putstr("enemy's positions:\n");
    display_map(game->map_enemy);
}

bool check_end_game(char **map)
{
    int max = 14;
    int res = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (map[i][j] == 'x')
                res++;
    return res == max ? false : true;
}