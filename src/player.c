/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** player
*/

#include "navy.h"
#include "my.h"

static void free_all(game_t *game)
{
    free(game->map_player);
    free(game->map_enemy);
    free(game);
}

static int end_game(game_t *game)
{
    if (check_end_game(game->map_enemy)) {
        my_putstr("I won\n");
        free_all(game);
        return 0;
    } else {
        my_putstr("Enemy won\n");
        free_all(game);
        return 1;
    }
}

static bool check_both_end(game_t *game)
{
    if (!check_end_game(game->map_enemy) || !check_end_game(game->map_player))
        return true;
    return false;
}

int player1(char *file)
{
    game_t *game = init_game(file);

    if (!game)
        return 84;
    game->status = attack;
    make_connection(game, 0, 1);
    while (!check_both_end(game)) {
        display_both_maps(game);
        if (game->status == attack && attack_loop(game) == 1)
            break;
        if (check_both_end(game))
            break;
        wait_loop(game);
    }
    return end_game(game);
}

int player2(int pid, char *file)
{
    game_t *game = init_game(file);

    if (!game)
        return 84;
    game->status = waiting_signal;
    make_connection(game, pid, 2);
    while (!check_both_end(game)) {
        display_both_maps(game);
        wait_loop(game);
        if (check_both_end(game))
            break;
        if (game->status == attack && attack_loop(game) == 1)
            break;
    }
    return end_game(game);
}
