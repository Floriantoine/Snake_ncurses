#include "param.h"
#include "body.hpp"
#include "enum/mode.h"
#include <menu.h>

const char *ncurse_main(int nb, char **argv)
{
   	ITEM **my_items;
	int n = 0;
	const char *output = NULL;
	MENU *my_menu;

	cbreak();
	my_items = malloc(sizeof(ITEM *) * (nb + 1));
    while (n < nb) {
		my_items[n] = new_item(argv[n], "\0");
        ++n;
    }
	my_items[nb] = (ITEM *)NULL;
	my_menu = new_menu(my_items);
	mvprintw(LINES - 2, 20, "Press SPACE to valid");
	mvprintw(LINES - 2, COLS - 20, "F1 to Exit");
	post_menu(my_menu);
	refresh();
	n = -1;

	while(n != ' ' && n != KEY_F(1))
	{
		n = getch();
		switch(n)
		{	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case KEY_LEFT:
				menu_driver(my_menu, REQ_PREV_ITEM);
				break;
			case KEY_RIGHT:
				menu_driver(my_menu, REQ_NEXT_ITEM);
				break;
		}
	}

	n = 0;
	output = current_item(my_menu)->name.str;
	while (my_items[n]) {
		free_item(my_items[n]);
		++n;
	}
	free_menu(my_menu);
	clear();
    return (output);
}