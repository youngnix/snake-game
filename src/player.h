#ifndef PLAYER_H
#define PLAYER_H

#include "food.h"
#include "linked_list.h"
#include "snake.h"

extern LinkedListNode* player_head;

void playerTexturesSetup();
void updatePlayer();
void renderPlayer();
unsigned char getPlayerDirection();
void movePlayer();
void playerEatItself();

#endif
