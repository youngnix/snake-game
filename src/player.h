#ifndef PLAYER_H
#define PLAYER_H

#include "fruit.h"
#include "snake.h"

extern SnakeSegment* player_snake_head;

void updatePlayer();
void updatePlayerDirection(char* direction_x, char* direction_y);
void renderPlayer();
void movePlayer();
char getPlayerEatFruit(Fruit* fruit);

#endif
