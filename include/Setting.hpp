/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Setting.hpp
*/

#pragma once
#include "Snake.hpp"
#include <ncurses.h>
#include "Obj.hpp"

class Setting
{
private:
    int _windowX;
    int _windowY;
    Snake _snake;
    std::vector<int> _eventKey;
    std::vector<objInf> _objVector;
public:
    void updateHUD();
    void newObj(int x, int y, ObjType enumObj);
    void saveEvent(int event);
    int getSnakeLife();
    void setWindow(int x, int y);
    int Update();
    Setting();
    ~Setting();
};