#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>

typedef struct SnakeSegment SnakeSegment;

typedef struct SnakeSegment {
	SnakeSegment* segment_link;
	int x, y;
} SnakeSegment;

int snakeSetup(SnakeSegment** snake_head);
void addSnakeSegment(SnakeSegment** snake_head);
unsigned int getSnakeSegmentCount(SnakeSegment** snake_head);
SnakeSegment* findPreviousSnakeSegment(SnakeSegment** snake_head, SnakeSegment** snake_segment);
SnakeSegment* findLastSnakeSegment(SnakeSegment** snake_head);
void freeSnake(SnakeSegment** snake_head);

#endif
