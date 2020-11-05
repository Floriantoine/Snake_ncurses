#include "body.hpp"
#include "lib_curses.h"

int pause_menu(void)
{
    char *argv[] = { "Play", "Menu", "Setting", "Exit"};
    char *option = NULL;
    int end = 0;

    while (end == 0)
    {
        option = ncurse_main(4, argv);
        if (strcmp(option, "Exit") == 0)
            return (1);
        if (strcmp(option, "Menu") == 0)
            end = 0;
        if (strcmp(option, "Setting") == 0)
            end =0;
        if (strcmp(option, "Play") == 0)
            return (0);
    }
    return (end);
}