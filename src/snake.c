#include "snake.h"
#include "linked_list.h"
#include "player.h"
#include "game.h"
#include <stdlib.h>

SnakeData* createSnakeData(int x, int y, char direction){
	SnakeData* snake_data = (SnakeData*)malloc(sizeof(SnakeData));

	snake_data->x = x;
	snake_data->y = y;
	snake_data->direction = direction;

	return snake_data;
}
