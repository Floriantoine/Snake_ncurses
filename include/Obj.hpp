/*
** EPITECH PROJECT, 2019
** ncurses
** File description:
** Obj.hpp
*/

#pragma once

enum ObjType
{
    NONE = 0,
    APPLE = 1,
    BOMBE = 2,
    LIFE = 3
};

struct objInf
{
    int x;
    int y;
    ObjType type;
};