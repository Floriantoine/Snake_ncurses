#include "param.h"
#include "body.hpp"
#include "obj_tools.h"

void anim_death(param_t *param)
{
    pos_t *tempo = param->index_pos;

    while (tempo != NULL) {
        attron(COLOR_PAIR(COLOR_RED));
        mvaddch(tempo->pos_y, tempo->pos_x, 'X');
        attroff(COLOR_PAIR(COLOR_RED));
        refresh();
        usleep(4000);
        tempo = tempo->next;
    }
}

int action_obj(param_t *param, obj_index_t *obj)
{
    if(obj->type == 0) {
        up_size(param);
        reset_obj(obj);
    } else if (obj->type == 1) {
        param->life = 0;
        anim_death(param);
    }
    return (0);
}

int check_obj_snake(pos_t *pos_snake, obj_index_t *obj_index, param_t *param)
{
    obj_index_t *tempo = obj_index;

    while(tempo != NULL) {
        if (pos_snake->pos_x == tempo->pos_x &&
        pos_snake->pos_y == tempo->pos_y) {
            action_obj(param, tempo);
            return (0);
        }
        tempo = tempo->next;
    }
    return (0);
}

int check_snake(param_t *param)
{
    check_obj_snake(param->index_pos, param->obj_index, param);
    if (param->index_pos->pos_x < 0 ||
    param->index_pos->pos_x > COLS)
        return (1);
    if (param->index_pos->pos_y < 0 ||
    param->index_pos->pos_y > LINES)
        return (1);
    return (0);
}