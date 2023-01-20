#include "game.h"
#include "food.h"
#include "linked_list.h"
#include "renderer.h"
#include "snake.h"
#include "window.h"
#include "player.h"
#include "keyboard.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>

const unsigned int GAME_AREA_WIDTH = 12;
const unsigned int GAME_AREA_HEIGHT = 8;

static char* food_sprite_list[] = { "res/apple.png", "res/cow.png", "res/python.png" };
static const unsigned int FOOD_SPRITE_LIST_SIZE = 3;

Game game = { 0 };

int gameSetup(){
	game.is_running = 1;

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		printf("SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	windowSetup(&main_window, MAIN_WINDOW_TITLE, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	rendererSetup(&main_renderer, &main_window);
	keyboardSetup();

	for(int i = 0; i < 2; i++){
		addLinkedListTailNode(&player_head, createSnakeData(0, 0, 0));
	}

	for(int i = 0; i < FOOD_SPRITE_LIST_SIZE; i++){
		addLinkedListTailNode(&game.food_texture_head, IMG_LoadTexture(main_renderer, food_sprite_list[i]));
	}

	for(int i = 0; i < 100; i++){
		addLinkedListTailNode(&game.food_head, createFood(rand() % GAME_AREA_WIDTH, rand() % GAME_AREA_HEIGHT, findRandomLinkedListNode(&game.food_texture_head)->data));
	}

	gameBeginLoop();

	gameCleanUp();
	return 0;
}

static void gameBeginLoop(){
	SDL_Event event;
	while(game.is_running == 1){
		clearKeyboard();

		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_KEYUP:
					eventKeyUp(&event);
				break;
				case SDL_KEYDOWN:
					if(!event.key.repeat){
						eventKeyDown(&event);
					}
				break;
				case SDL_QUIT:
					game.is_running = 0;
				break;
				default:
				break;
			}
		}

		updatePlayer();

		for(LinkedListNode* ptr = game.food_head; ptr != NULL; ptr = ptr->link){
			for(LinkedListNode* snake_ptr = player_head; snake_ptr != NULL; snake_ptr = snake_ptr->link){
				while(isFoodOnSnake(&snake_ptr, ptr->data)){
					ptr->data = createFood(rand() % GAME_AREA_WIDTH, rand() % GAME_AREA_HEIGHT, findRandomLinkedListNode(&game.food_texture_head)->data);
				}
			}
		}

		gameRender();
	}
}

int gameCleanUp(){
	SDL_DestroyRenderer(main_renderer);
	SDL_DestroyWindow(main_window);
	SDL_Quit();

	return 0;
}

static void gameRender(){
	SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);

	SDL_RenderClear(main_renderer);

	renderPlayer();

	for(LinkedListNode* ptr = game.food_head; ptr != NULL; ptr = ptr->link){
		renderFood(ptr->data);
	}
	
	SDL_RenderPresent(main_renderer);
}
