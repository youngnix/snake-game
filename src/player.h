#ifndef PLAYER_H
#define PLAYER_H

#include "food.h"
#include "linked_list.h"
#include "snake.h"

extern LinkedListNode* player_head;

void updatePlayer();
void renderPlayer();
void updatePlayerDirection();
void movePlayer();

#endif
