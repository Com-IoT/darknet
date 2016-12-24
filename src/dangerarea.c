/*
 * dangerarea.c
 *
 *  Created on: Dec 19, 2016
 *      Author: behema
 */


#include "dangerarea.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

dangerarea make_dangerarea(int top, int bot,int right,int left){
	dangerarea area;
	area.top = top;
	area.bot = bot;
	area.right = right;
	area.left = left;
	return area;
}

void draw_dangerarea(image im, dangerarea area){
	box bbox;
	bbox.x = area.top;
	bbox.h = area.bot-area.top;
	bbox.y = area.left;
	bbox.w = area.right-area.left;
	draw_bbox(im, bbox, 3, 255,0,0);
}
