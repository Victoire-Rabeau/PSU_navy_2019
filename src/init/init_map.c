/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** init_map
*/

#include "navy.h"
#include "my.h"

char **get_file(char *filename)
{
    char **file = malloc(sizeof(char *) * 5);
    FILE *stream = NULL;
    size_t len = 0;

    if (!file)
        return NULL;
    for (int i = 0; i < 5; i++)
        file[i] = NULL;
    if (!(stream = fopen(filename, "r"))) {
        my_putstr("Invalid filename\n");
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (getline(&file[i], &len, stream) == -1)
            return NULL;
        file[i][7] = '\0';
    }
    return file;
}

bool check_file(char **file)
{
    for (int i = 0; i < 4; i++) {
        if (my_strlen(file[i]) != 7)
            return false;
        if (file[i][0] != ('0' + i + 2) || file[i][1] != ':'
            || file[i][4] != ':')
            return false;
        if (!check_pos(file[i][2], file[i][3])
            || !check_pos(file[i][5], file[i][6]))
            return false;
    }
    return true;
}

bool check_gaps(char **file)
{
    int size = 0;
    int high = 0;
    int len = 0;

    for (int i = 0; i < 4; i++) {
        size = file[i][0] - '0' - 1;
        high = file[i][5] - file[i][2];
        len = file[i][6] - file[i][3];
        if ((high == size && len == 0) || (len == size && high == 0))
            continue;
        return false;
    }
    return true;
}

char **get_orientation_navy(int *pos, int size, char **map)
{
    if (pos[0] == pos[2]) {
        for (int i = 0; i < size; i++)
            map[pos[1] + i - 1][pos[0]] = size + '0';
        return map;
    }
    for (int i = 0; i < size; i++)
        map[pos[1] - 1][pos[0] + i] = size + '0';
    return map;
}

char **fill_map(char **file)
{
    char **map = init_empty_map();
    int *pos = malloc(sizeof(int) * 3);
    int size = 0;

    if (!map)
        return NULL;
    for (int i = 0; i < 4; i++) {
        size = file[i][0] - '0';
        pos[0] = file[i][2] - 'A';
        pos[1] = file[i][3] - '0';
        pos[2] = file[i][5] - 'A';
        map = get_orientation_navy(pos, size, map);
    }
    free(pos);
    return map;
}
