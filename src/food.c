#include "food.h"
#include "renderer.h"
#include "game.h"
#include "snake.h"

Food* createFood(int x, int y, SDL_Texture* texture){
	Food* food = (Food*)malloc(sizeof(Food));

	food->x = x;
	food->y = y;
	food->texture = texture;

	return food;
}

void renderFood(Food* food){
	if(food->texture == NULL){
		SDL_SetRenderDrawColor(main_renderer, 255, 0, 0, 255);

		SDL_Rect rect = {
			.x = food->x * 16 + 1,
			.y = food->y * 16 + 1,
			.w = 14,
			.h = 14,
		};

		SDL_RenderFillRect(main_renderer, &rect);

		return;
	}

	SDL_Rect texture_rectangle = {
		.x = food->x * 16,
		.y = food->y * 16,
		.w = 16,
		.h = 16,
	};

	SDL_RenderCopy(main_renderer, food->texture, NULL, &texture_rectangle);
}

int isFoodOnSnake(LinkedListNode** snake_head, Food* food){
	for(LinkedListNode* ptr = *snake_head; ptr != NULL; ptr = ptr->link){
		if(food->x == ((SnakeData*)ptr->data)->x
		&& food->y == ((SnakeData*)ptr->data)->y){
			return 1;
		}
	}

	return 0;
}

void freeFood(Food* food){
	free(food);
}
