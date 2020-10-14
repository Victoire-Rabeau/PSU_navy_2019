/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** loop
*/

#include "navy.h"
#include "my.h"

void await_attack(bool hit)
{
    extern int pos;

    if (hit && (signal(SIGUSR2, attack_handler) == SIG_ERR ||
        signal(SIGUSR1, attack_handler) == SIG_ERR))
        my_putstr("can't catch signal\n");
    if (!hit && (signal(SIGUSR2, await_sigattk) == SIG_ERR ||
        signal(SIGUSR1, await_sigattk) == SIG_ERR))
        my_putstr("can't catch signal\n");
    while (pos == -1)
        usleep(1e6 * 2);
}

void wait_loop(game_t *game)
{
    extern int pos;
    vec2_t idx = {0};

    pos = -1;
    my_putstr("waiting for enemy's attack...\n");
    await_attack(true);
    idx.x = pos % 8;
    idx.y = pos / 8;
    game->hit = is_hit(game, &idx);
    my_putstr(reverse_get_pos(&idx));
    my_putstr(game->hit ? ": hit\n\n" : ": missed\n\n");
    update_map(game->map_player, reverse_get_pos(&idx), game->hit);
    usleep(1e6);
    kill(game->pid, game->hit ? SIGUSR1 : SIGUSR2);
    game->status = attack;
}

static void update_line(char *line, game_t *game)
{
    extern int pos;

    line[my_strlen(line) - 1] = '\0';
    my_putstr(line);
    my_putstr(pos == -2 ? ": hit\n\n" : ": missed\n\n");
    update_map(game->map_enemy, line, pos == -2 ? true : false);
}

static int send_attack(char *line, game_t *game)
{
    if (!(line = read_term()))
        return 1;
    while (!check_line(line)) {
        my_putstr("wrong position\nattack: ");
        if (!(line = read_term()))
            return 1;
    }
    game->attack = get_pos(line);
    send_number(game->attack, 8, game->pid);
    await_attack(false);
    update_line(line, game);
    return 0;
}

int attack_loop(game_t *game)
{
    extern int pos;
    char *line = NULL;

    pos = -1;
    my_putstr("attack: ");
    send_attack(line, game);
    return 0;
}