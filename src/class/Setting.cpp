/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Snake.cpp
*/

#include "Setting.hpp"
#include "ncurses.h"
#include "Body.hpp"

void Setting::saveEvent(int event)
{
    if (event != -1)
        _eventKey.push_back(event);
}

int Setting::getSnakeLife()
{
    return _snake.getLife();
}

void Setting::setWindow(int x, int y)
{
    _windowX = x;
    _windowY = y;
}

void Setting::newObj(int x, int y, ObjType type)
{
    _objVector.push_back(objInf({x, y, type}));
}

void Setting::updateHUD()
{
    mvprintw(1, 0, "     /\\\\\\\\\\\\\\\\\\\\\\    /\\\\\\\\\\     /\\\\\\     /\\\\\\\\\\\\\\\\\\     /\\\\\\        /\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                /^\\/^\\");
    mvprintw(2, 0, "    /\\\\\\/////////\\\\\\ \\/\\\\\\\\\\\\   \\/\\\\\\   /\\\\\\\\\\\\\\\\\\\\\\\\\\  \\/\\\\\\     /\\\\\\//  \\/\\\\\\///////////              _|__|  O|");
    mvprintw(3, 0, "    \\//\\\\\\      \\///  \\/\\\\\\/\\\\\\  \\/\\\\\\  /\\\\\\/////////\\\\\\ \\/\\\\\\  /\\\\\\//     \\/\\\\\\               \\/     /~     \\_/ \\");
    mvprintw(4, 0, "      \\////\\\\\\         \\/\\\\\\//\\\\\\ \\/\\\\\\ \\/\\\\\\       \\/\\\\\\ \\/\\\\\\\\\\\\//\\\\\\     \\/\\\\\\\\\\\\\\\\\\\\\\        \\____|__________/  \\");
    mvprintw(5, 0, "          \\////\\\\\\      \\/\\\\\\\\//\\\\\\\\/\\\\\\ \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\/\\\\\\//  //\\\\\\     /\\\\\\///////               \\_______      \\");
    mvprintw(6, 0, "              \\////\\\\\\   \\/\\\\\\ \\//\\\\\\/\\\\\\ \\/\\\\\\/////////\\\\\\ \\/\\\\\\     //\\\\\\   \\/\\\\\\                             `\\     \\                 \\");
    mvprintw(7, 0, "        /\\\\\\      \\//\\\\\\  \\/\\\\\\  \\//\\\\\\\\\\\\ \\/\\\\\\       \\/\\\\\\ \\/\\\\\\     \\//\\\\\\  \\/\\\\\\                              |     |                  \\");
    mvprintw(8, 0, "        \\///\\\\\\\\\\\\\\\\\\\\\\/   \\/\\\\\\   \\//\\\\\\\\\\ \\/\\\\\\       \\/\\\\\\ \\/\\\\\\      \\//\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                /      /                    \\");
    mvprintw(9, 0, "           \\///////////     \\///     \\/////  \\///        \\///  \\///        \\///  \\///////////////               /     /                       \\\\");

    for(int i = 0 ; i < 3; i++) {
        if (i < _snake.getLife())
            attron(COLOR_PAIR(1));
        mvprintw(0, _windowX - i * 6 - 6, " _  _");
        mvprintw(1, _windowX - i * 6 - 6, "( `' )");
        mvprintw(2, _windowX - i * 6 - 6, " `.,'");
        if (i < _snake.getLife())
            attroff(COLOR_PAIR(1));
    }
    mvprintw(HUD_SIZE - 2, _windowX - 35, "APPLE:   | BOMBE:   | LIFE:  ");
    attron(COLOR_PAIR(1));
    mvaddch(HUD_SIZE - 2, _windowX - 28, 'O');
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(5));
    mvaddch(HUD_SIZE - 2, _windowX - 17, 'X');
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(7));
    mvaddch(HUD_SIZE - 2, _windowX - 7, 'L');
    attroff(COLOR_PAIR(7));
    for(int i = 0 ; i < _windowX; i++)
        mvaddch(HUD_SIZE - 1, i, 'X');
}

int Setting::Update()
{
    clear();
    updateHUD();
    _windowX = getmaxx(stdscr);
    _windowY =getmaxy(stdscr);
    ObjType objEat = _snake.Update(_eventKey, _objVector);
    if (objEat != ObjType::NONE)
        _objVector.push_back(objInf({randy(5, _windowX - 5, -1), randy(HUD_SIZE + 5, _windowY - 5, -1), objEat}));
    for (auto const& elem : _objVector) {
        if (elem.type == ObjType::APPLE) {
            attron(COLOR_PAIR(1));
            mvaddch(elem.y, elem.x, 'O');
            attroff(COLOR_PAIR(1));
        } else if (elem.type == ObjType::BOMBE) {
            attron(COLOR_PAIR(5));
            mvaddch(elem.y, elem.x, 'X');
            attroff(COLOR_PAIR(5));
        } else if (elem.type == ObjType::LIFE) {
            attron(COLOR_PAIR(7));
            mvaddch(elem.y, elem.x, 'L');
            attroff(COLOR_PAIR(7));
        }
    }
    _eventKey.clear();
    refresh();
    return 0;
}

Setting::Setting(): _windowX(getmaxx(stdscr)), _windowY(getmaxy(stdscr)), _snake(_windowX / 2 , _windowY / 2)
{
    for (size_t i = 0; i < 8; i++) {
        _objVector.push_back(objInf({randy(5, _windowX - 5, -1), randy(HUD_SIZE + 5, _windowY - 5, -1), APPLE}));
        _objVector.push_back(objInf({randy(5, _windowX - 5, -1), randy(HUD_SIZE + 5, _windowY - 5, -1), BOMBE}));
    }
    _objVector.push_back(objInf({randy(5, _windowX - 5, -1), randy(HUD_SIZE + 5, _windowY - 5, -1), LIFE}));
}

Setting::~Setting()
{
}
