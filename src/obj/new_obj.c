/*
** EPITECH PROJECT, 2018
** snake
** File description:
** new_obj.c
*/

#include "param.h"
#include "body.hpp"
#include "lib_curses.h"
#include "stdlib.h"

void print_obj(param_t *param)
{
    obj_index_t *tempo = param->obj_index;

    while (tempo != NULL) {
        if (tempo->type == 1)
            mvaddch(tempo->pos_y, tempo->pos_x, 'X');
        if (tempo->type == 0) {
            attron(COLOR_PAIR(COLOR_RED));
            mvaddch(tempo->pos_y, tempo->pos_x, 'O');
            attroff(COLOR_PAIR(COLOR_RED));
        }
        tempo = tempo->next;
    }
    refresh();
}

void reset_obj(obj_index_t *obj)
{
    obj->pos_x = randy(5, COLS, 0);
    obj->pos_y = randy(5, LINES, 0);
}

void new_obj_rand(param_t *param)
{
    obj_index_t *tempo = param->obj_index;
    obj_index_t *new = NULL;

    while(tempo->next != NULL)
        tempo = tempo->next;
    new = malloc(sizeof(obj_index_t) * 1);
    new->pos_x = randy(5, param->window_x, 0);
    new->pos_y = randy(5, param->window_y, 0);
    new->type = randy(0, 2, 2);
    new->next = NULL;
    tempo->next = new;
}

void new_obj(param_t *param, int type)
{
    obj_index_t *tempo = param->obj_index;
    obj_index_t *new = NULL;

    while(tempo->next != NULL)
        tempo = tempo->next;
    new = malloc(sizeof(obj_index_t) * 1);
    new->pos_x = randy(5, param->window_x, 0);
    new->pos_y = randy(5, param->window_y, 0);
    new->type = type;
    new->next = NULL;
    tempo->next = new;
}