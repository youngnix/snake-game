#include "food.h"
#include "renderer.h"
#include "game.h"
#include "snake.h"
#include "window.h"

Food* createFood(int x, int y, SDL_Texture* texture){
	Food* food = (Food*)malloc(sizeof(Food));

	food->x = x;
	food->y = y;
	food->texture = texture;

	return food;
}

void renderFood(Food* food){
	renderRectangle(food->x * WINDOW_SCALE_MULTIPLIER + 1, food->y * WINDOW_SCALE_MULTIPLIER + 1, WINDOW_SCALE_MULTIPLIER - 2, WINDOW_SCALE_MULTIPLIER - 2, 0xFF0000FF);
}

int isFoodOnSnake(LinkedListNode** snake_head, Food* food){
	SnakeSegment* snake_data = (*snake_head)->data;
	
	for(LinkedListNode* ptr = *snake_head; ptr != NULL; ptr = ptr->link){
		if(snake_data->x == food->x
		&& snake_data->y == food->y){
			return 1;
		}
	}
	
	return 0;
}

void freeFood(Food* food){
	free(food);
}
