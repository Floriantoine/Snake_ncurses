/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for Dante solver
*/

#include <iostream>
#include "Setting.hpp"
#include "Body.hpp"
#include "lib_curses.h"
#include <ctime>

int init()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    nodelay(stdscr, true);
    if (has_colors() == FALSE) {
        std::cerr << "Your terminal does not support color\n" << std::endl;
        return (1);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    return (0);
}

int main(void)
{
    std::srand(std::time(NULL));

    if (init())
        return (84);

    Setting setting;
    if (body(&setting)) {
        endwin();
        return (84);
    }
    endwin();
    return (0);
}