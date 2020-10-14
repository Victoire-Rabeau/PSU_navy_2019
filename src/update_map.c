/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** update_map
*/

#include "navy.h"
#include "my.h"

char *reverse_get_pos(vec2_t *idx)
{
    char *attack = malloc(sizeof(char) * 3);

    if (!attack)
        return NULL;
    attack[0] = idx->x + 'A';
    attack[1] = idx->y + '1';
    attack[2] = '\0';
    return attack;
}

bool is_hit(game_t *game, vec2_t *idx)
{
    int y = idx->y;
    int x = idx->x;

    return (game->hit = (game->map_player[y][x] >= '2' &&
                        game->map_player[y][x] <= '5') ? true : false);
}

void update_map(char **map, char *position, bool hit)
{
    int pos = get_pos(position);
    int x = pos % 8;
    int y = pos / 8;
    if (map[y][x] == 'x')
        return;
    map[y][x] = (!hit && (map[y][x] == '.' || map[y][x] == 'o')) ? 'o' : 'x';
}

int get_pos(char *attack)
{
    int x = attack[0] - 'A';
    int y = attack[1] - '1';

    return y * 8 + x;
}

bool check_line(char *line)
{
    return my_strlen(line) != 3 ? false : check_pos(line[0], line[1]);
}
