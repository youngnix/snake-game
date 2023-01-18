#include "fruit.h"
#include "renderer.h"
#include "snake.h"
#include <stdlib.h>

Fruit createFruit(int x, int y){
	Fruit fruit = { .x = x, .y = y };

	return fruit;
}

void moveFruit(Fruit* fruit, int x, int y){
	fruit->x = x;
	fruit->y = y;
}

void renderFruit(Fruit* fruit){
	SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);

	SDL_Rect rect = {
		.x = fruit->x * 8 + 1,
		.y = fruit->y * 8 + 1,
		.w = 6,
		.h = 6,
	};

	SDL_RenderFillRect(main_renderer, &rect);
}

char isFruitOnSnake(Fruit fruit, SnakeSegment** snake_head){
	for(SnakeSegment* segment_pointer = *snake_head; segment_pointer != NULL; segment_pointer = segment_pointer->segment_link){
		if(fruit.x == segment_pointer->x
		&& fruit.y == segment_pointer->y) return 1;
	}

	return 0;
}
