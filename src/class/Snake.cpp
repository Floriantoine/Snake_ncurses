/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

int Snake::getLife() const
{
    return _life;
}

void Snake::checkEntry(int entry)
{
    if (entry == 260 || entry == 261) {
        _dirY = 0;
        if (entry == 261 && _dirX != -1)
            _dirX = 1;
        if (entry == 260 && _dirX != 1)
            _dirX = -1;
    } else if (entry == 258 || entry == 259) {
        _dirX = 0;
        if (entry == 259 && _dirY != 1)
            _dirY = -1;
        if (entry == 258 && _dirY != -1)
            _dirY = 1;
    }
}

int Snake::moveSnake()
{
    if (_bodyChain.size() > (size_t)_size)
        _bodyChain.erase(_bodyChain.begin());
    _bodyChain.push_back(body({_bodyChain[_bodyChain.size() - 1].x + _dirX,
        _bodyChain[_bodyChain.size() - 1].y + _dirY}));
    return (0);
}

void Snake::checkSelfColli()
{
    body head = _bodyChain[_bodyChain.size() - 1];

    if (head.x < 0 || head.x > _windowX || head.y < HUD_SIZE ||
        head.y > _windowY)
        _life = 0;
    if (_bodyChain.size() < 5)
        return;
    for (size_t i = 0; i < _bodyChain.size() - 1; i++) {
        if (head.x == _bodyChain[i].x && head.y == _bodyChain[i].y) {
            _life--;
            return;
        }
    }
}

ObjType Snake::checkObjColli(body bodyInf, std::vector<objInf> &objVector)
{
    ObjType typeObjEat = ObjType::NONE;
    body head = _bodyChain[_bodyChain.size() - 1];
    size_t i = 0;

    for (auto &elem: objVector) {
        if (elem.x == bodyInf.x && elem.y == bodyInf.y) {
            if (elem.type == ObjType::APPLE)
                _size += 4;
            else if (elem.type == ObjType::BOMBE) {
                attron(COLOR_PAIR(1));
                mvprintw(head.y - 2, head.x - 3, "'.\\|/.'");
                mvprintw(head.y - 1, head.x - 3, "(\\   /)");
                mvprintw(head.y, head.x - 3, "- -O- -");
                mvprintw(head.y + 1, head.x - 3, "(/   \\)");
                mvprintw(head.y + 2, head.x - 3, ",'/|\'.");
                attroff(COLOR_PAIR(1));
                _life -= 1;
            } else if (elem.type == ObjType::LIFE && _life < 3)
                _life++;
            typeObjEat = elem.type;
            objVector.erase(objVector.begin() + i);
            return typeObjEat;
        }
        ++i;
    }
    return typeObjEat;
}

ObjType Snake::Update(std::vector<int> eventKey, std::vector<objInf> &objVector)
{
    _windowX = getmaxx(stdscr);
    _windowY = getmaxy(stdscr);
    checkSelfColli();
    for (auto const &elem: eventKey)
        checkEntry(elem);
    for (auto const &elem: this->_bodyChain) {
        attron(COLOR_PAIR(3));
        mvaddch(elem.y, elem.x, 'O');
        attroff(COLOR_PAIR(3));
    }
    moveSnake();
    return checkObjColli(_bodyChain[_bodyChain.size() - 1], objVector);
}

void Snake::upSize(int x, int y)
{
    _size++;
    _bodyChain.push_back(body({x, y}));
}

Snake::Snake(int x, int y)
    : _windowX(getmaxx(stdscr)), _windowY(getmaxy(stdscr))
{
    _life = 1;
    _size = 3;
    _dirX = 1;
    _dirY = 0;
    upSize(x, y);
    upSize(x, y);
    upSize(x, y);
}

Snake::~Snake()
{
}
