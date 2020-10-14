/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** init_struct
*/

#include "navy.h"
#include "my.h"

bool check_pos(char col, char line)
{
    return ((col < 'A' || col > 'H') || (line < '1' || line > '8')) ? false : true;
}

char **init_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 8);
    int j = 0;

    if (!map)
        return NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        if (!map[i])
            return NULL;
        j = 0;
        for (; j < 8; j++)
            map[i][j] = '.';
        map[i][j] = '\0';
    }
    return map;
}

char **get_map_player(char *filename)
{
    char **file = get_file(filename);

    if (!file)
        return NULL;
    if (!check_file(file)) {
        my_putstr("Invalid file\n");
        return NULL;
    }
    if (!check_gaps(file)) {
        my_putstr("Invalid positions\n");
        return NULL;
    }
    return fill_map(file);
}

game_t *init_game(char *file)
{
    extern int pos;
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->map_player = get_map_player(file);
    game->map_enemy = init_empty_map();
    game->attack = 0;
    game->pid = 0;
    game->hit = false;
    game->status = 0;
    pos = -1;
    return (!game->map_player || !game->map_enemy) ? NULL : game;
}

char *read_term(void)
{
    char *line = NULL;
    size_t len = 0;

    return getline(&line, &len, stdin) == -1 ?  NULL : line;
}
