#include "param.h"
#include "body.hpp"
#include "lib_curses.h"
#include "obj_tools.h"
#include <stdlib.h>

int init_obj(param_t *param)
{
    param->obj_index = malloc(sizeof(obj_index_t) * 1);
    if (param->obj_index == NULL)
        return (1);
    param->obj_index->next = NULL;
    param->obj_index->pos_x = randy(5, param->window_x, 0);
    param->obj_index->pos_y = randy(5, param->window_y, 0);
    param->obj_index->type = 0;
    new_obj(param, 0);
    new_obj(param, 0);
    new_obj(param, 1);
    return (0);
}