/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** connection
*/

#include "navy.h"
#include "my.h"

static void connect(game_t *game, int pid)
{
    send_number(getpid(), 22, pid);
    game->pid = pid;
    my_putstr("\nsuccessfully connected\n\n");
}

static void connection_handler(int signo)
{
    extern int pos;
    static int call_num = 0;
    static int num = 0;

    num = (num << 1) | (signo == SIGUSR2);
    if (call_num++ == 21) {
        pos = num;
        call_num = 0;
    }
}


static void await_connection(game_t *game)
{
    extern int pos;

    my_putstr("\nwaiting for enemy connection...\n");
    if (signal(SIGUSR2, connection_handler) == SIG_ERR ||
        signal(SIGUSR1, connection_handler) == SIG_ERR)
        my_putstr("can't catch signal\n");
    while (pos == -1)
        usleep(1e4);
    game->pid = pos;
    my_putstr("\nenemy connected\n\n");
}

void make_connection(game_t *game, int pid, int player)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    if (player == 1)
        await_connection(game);
    else
        connect(game, pid);
}