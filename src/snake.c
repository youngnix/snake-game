#include "snake.h"
#include "linked_list.h"
#include "player.h"
#include "game.h"
#include "window.h"
#include <stdlib.h>

SnakeSegment* createSnakeSegment(int x, int y, unsigned char direction){
	SnakeSegment* segment = (SnakeSegment*)malloc(sizeof(SnakeSegment));

	segment->x = x;
	segment->y = y;
	segment->direction = direction;

	return segment;
}

void renderSnakeSegment(SnakeSegment* segment){
	if(segment == NULL)
		return;
	
	renderRectangle(segment->x * WINDOW_SCALE_MULTIPLIER, segment->y * WINDOW_SCALE_MULTIPLIER, WINDOW_SCALE_MULTIPLIER, WINDOW_SCALE_MULTIPLIER, 0xFFFFFFFF);
}

int isSnakeSegmentOnFood(SnakeSegment* segment, Food* food){
	if(segment == NULL){
		fprintf(stderr, "@%s: invalid segment (%p).\n", __func__, segment);
		return -1;
	}

	if(food == NULL){
		fprintf(stderr, "@%s: invalid food (%p).\n", __func__, food);
		return -1;
	}

	if(segment->x == food->x
	   && segment->y == food->y){
		return 1;
	}
	
	return 0;
}
