/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int pos;

enum player_status {
    attack,
    waiting_signal,
    loose,
    win
};

typedef struct vec2_s {
    int x;
    int y;
} vec2_t;

typedef struct game_s {
    bool hit;
    char **map_player;
    char **map_enemy;
    int attack;
    int pid;
    int status;
} game_t;

int player1(char *file);
int player2(int pid, char *file);

char **init_empty_map(void);
char **get_map_player(char *file);
game_t *init_game(char *file);
char *read_term(void);

char **get_file(char *filename);
bool check_line(char *line);
bool check_file(char **file);
bool check_gaps(char **file);
bool check_pos(char col, char line);
bool is_hit(game_t *game, vec2_t *idx);
char **get_orientation_navy(int *pos, int size, char **map);
char **fill_map(char **file);

void update_map(char **map, char *position, bool hit);

void make_connection(game_t *game, int pid, int player);
void send_number(int number, int size, int pid);
void attack_handler(int signo);
void await_sigattk(int signo);

void display_both_maps(game_t *game);
void display_map(char **map);

int get_pos(char *attack);
char *reverse_get_pos(vec2_t *idx);

void wait_loop(game_t *game);
int attack_loop(game_t *game);

bool check_end_game(char **map);
#endif /* !NAVY_H_ */
