#ifndef SNAKE_H
#define SNAKE_H

#include "food.h"
#include "linked_list.h"
#include <SDL2/SDL.h>

typedef struct SnakeSegment SnakeSegment;

typedef struct SnakeSegment {
	int x, y;
	unsigned char direction;
} SnakeSegment;

SnakeSegment* createSnakeSegment(int x, int y, unsigned char direction);
void renderSnakeSegment(SnakeSegment* segment);
int isSnakeSegmentOnFood(SnakeSegment* segment, Food* food);

#endif
