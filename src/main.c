/*
** EPITECH PROJECT, 2020
** refacto-navy
** File description:
** main
*/

#include "navy.h"
#include "my.h"

static int display_help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIPTION\n\
\tfirst_player_pid: only for the 2nd player. pid of the first player.\n\tnavy_p\
ositions: file representing the positions of the ships.\n");
    return 0;
}

static int arguments_management(int ac, char **av)
{
    if (ac == 2 && my_strcmp("-h", av[1]))
        return display_help();
    if (ac < 2 || ac > 3) {
        my_putstr("Invalid number of arguments: 2 or 3 expected\n");
        return 84;
    }
    if (ac == 3 && my_getnbr(av[1]) < 1) {
        my_putstr("Invalid pid\n");
        return 84;
    }
    return 1;
}

int main(int ac, char **av)
{
    int r = arguments_management(ac, av);
    extern int pos;

    pos = 0;
    if (r != 1)
        return r;
    return ac == 2 ? player1(av[1]) : player2(my_getnbr(av[1]), av[2]);
}
