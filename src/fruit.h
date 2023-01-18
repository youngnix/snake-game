#ifndef FRUIT_H
#define FRUIT_H

#include "snake.h"
typedef struct Fruit Fruit;

typedef struct Fruit {
	int x, y;
} Fruit;

Fruit createFruit(int x, int y);
void moveFruit(Fruit* fruit, int x, int y);
void renderFruit(Fruit* fruit);
char isFruitOnSnake(Fruit fruit, SnakeSegment** snake_head);

#endif
