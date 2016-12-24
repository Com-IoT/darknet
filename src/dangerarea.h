/*
 * dangerarea.h
 *
 *  Created on: Dec 19, 2016
 *      Author: behema
 */

#ifndef SRC_DANGERAREA_H_
#define SRC_DANGERAREA_H_
#include "image.h"

typedef struct dangerarea{
    int top, bot, right, left;
} dangerarea;

dangerarea make_dangerarea(int top, int bot,int right,int left);

void draw_dangerarea(image im, dangerarea area);

#endif /* SRC_DANGERAREA_H_ */
