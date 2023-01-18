#include "player.h"
#include "game.h"
#include "keyboard.h"
#include "snake.h"
#include "renderer.h"
#include <stdio.h>

SnakeSegment* player_snake_head;

void updatePlayer(){
	static int tick_counter = 0;

	static char direction_x, direction_y = 0;

	updatePlayerDirection(&direction_x, &direction_y);

	if(tick_counter >= 50){
		tick_counter = 0;
		
		for(SnakeSegment* segment_pointer = findLastSnakeSegment(&player_snake_head); segment_pointer != player_snake_head; segment_pointer = findPreviousSnakeSegment(&player_snake_head, &segment_pointer)){
			const SnakeSegment* previous_segment = findPreviousSnakeSegment(&player_snake_head, &segment_pointer);
			segment_pointer->x = (previous_segment->x + GAME_AREA_WIDTH + 1) % GAME_AREA_WIDTH;
			segment_pointer->y = (previous_segment->y + GAME_AREA_HEIGHT + 1) % GAME_AREA_HEIGHT;
		}

		player_snake_head->x += direction_x;
		player_snake_head->y += direction_y;
		
		player_snake_head->x = (player_snake_head->x + GAME_AREA_WIDTH + 1) % GAME_AREA_WIDTH;
		player_snake_head->y = (player_snake_head->y + GAME_AREA_HEIGHT + 1) % GAME_AREA_HEIGHT;
	}

	tick_counter++;
}

void renderPlayer(){
	for(SnakeSegment* segment_pointer = player_snake_head; segment_pointer != NULL; segment_pointer = segment_pointer->segment_link){
		SDL_Rect rect = {
			.x = segment_pointer->x * 8 + 1,
			.y = segment_pointer->y * 8 + 1,
			.w = 6,
			.h = 6,
		};

		SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(main_renderer, &rect);
	}
}

void updatePlayerDirection(char* direction_x, char* direction_y){
	if(*direction_x != 1 && getKeyPressed(SDL_SCANCODE_LEFT)){
		*direction_x = -1;
		*direction_y = 0;
	}
	if(*direction_x != -1 && getKeyPressed(SDL_SCANCODE_RIGHT)){
		*direction_x = 1;
		*direction_y = 0;
	}
	if(*direction_y != 1 && getKeyPressed(SDL_SCANCODE_UP)){
		*direction_x = 0;
		*direction_y = -1;
	}
	if(*direction_y != -1 && getKeyPressed(SDL_SCANCODE_DOWN)){
		*direction_x = 0;
		*direction_y = 1;
	}
}

char getPlayerEatFruit(Fruit* fruit){
	if(player_snake_head->x == fruit->x
	&& player_snake_head->y == fruit->y){
		addSnakeSegment(&player_snake_head);
		return 1;
	}

	return 0;
}
