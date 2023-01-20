#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>

typedef struct SnakeData SnakeData;

typedef struct SnakeData {
	int x, y;
	char direction;
} SnakeData;

SnakeData* createSnakeData(int x, int y, char direction);

#endif
