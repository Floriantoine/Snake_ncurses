/*
** EPITECH PROJECT, 2019
** snake
** File description:
** snake.hpp
*/

#pragma once
#include <vector>
#include "Obj.hpp"
#include "ncurses.h"
#define HUD_SIZE 12

struct body
{
    int x;
    int y;
};

class Snake
{
private:
    int _windowX;
    int _windowY;
    int _size;
    int _dirX;
    int _dirY;
    int _life;
    std::vector<body> _bodyChain;
public:
    void checkSelfColli();
    ObjType checkObjColli(body bodyInf, std::vector<objInf>& objVector);
    void checkEntry(int entry);
    ObjType Update(std::vector<int> eventKey, std::vector<objInf>& objVector);
    void upSize(int x, int y);
    int moveSnake();
    int getLife() const;
    Snake(int x, int y);
    ~Snake();
};
