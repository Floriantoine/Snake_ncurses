#include "param.h"
#include "setting.h"
#include <stdio.h>
#include <string.h>
#include "lib_curses.h"

int take_key(void)
{
    int loop = 0;
    int key = -1;

    mvprintw(LINES / 2, COLS / 2, "Press A KEY:");
    while (key == -1) {
        if (loop == 0) {
            mvprintw(LINES / 2, (COLS / 2) + 13, "?");
            loop = 1;
        } else {
            loop = 0;
            mvprintw(LINES / 2, (COLS / 2) + 13, " ");
        }
        key = getch();
        refresh();
    }
    clear();
    return (key);
}

int keyBind(param_t *param)
{
    (void)param;
    char *setting[] = {"Key_Up", "Key_Down", "Exit"};
    char * output = NULL;
    int end = 0;

    while (end == 0) {
        output = ncurse_main(3, setting);
        if (strcmp(output, "Key_Left") == 0)
            param->key_index.key_left = take_key();
        if (strcmp(output, "Exit") == 0)
            end = 1;
    }
    return (0);
}


int setting(param_t *param)
{
    (void)param;
    char *setting[] = {"Keybind", "...", "Exit"};
    char * output = NULL;
    int end = 0;

    while (end == 0) {
        output = ncurse_main(3, setting);
        if (strcmp(output, "Keybind") == 0)
            keyBind(param);
        if (strcmp(output, "Exit") == 0)
            end = 1;
    }
    return (0);
}