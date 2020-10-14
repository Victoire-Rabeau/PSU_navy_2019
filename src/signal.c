/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** signal
*/

#include "navy.h"
#include "my.h"

void send_number(int number, int size, int pid)
{
    for (int i = size - 1; i >= 0; i--) {
        kill(pid, (number >> i) & 1 ? SIGUSR2 : SIGUSR1);
        usleep(1e4);
    }
}

void attack_handler(int signo)
{
    extern int pos;
    static int call_num = 0;
    static int num = 0;

    num = (num << 1) | (signo == SIGUSR2);
    if (call_num++ == 7) {
        pos = num;
        call_num = 0;
        num = 0;
    }
}

void await_sigattk(int signo)
{
    extern int pos;

    pos = signo == SIGUSR1 ? -2 : -3;
}