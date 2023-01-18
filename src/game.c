#include "game.h"
#include "fruit.h"
#include "renderer.h"
#include "snake.h"
#include "window.h"
#include "player.h"
#include "keyboard.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>

const unsigned int GAME_AREA_WIDTH = 24;
const unsigned int GAME_AREA_HEIGHT = 12;

static Game game = { 0 };

int gameSetup(){
	game.is_running = 1;

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		printf("SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	windowSetup(&main_window, "Title", 1280, 720);
	rendererSetup(&main_renderer, &main_window);

	keyboardSetup();

	snakeSetup(&player_snake_head);

	game.fruit = createFruit(rand() % GAME_AREA_WIDTH + 1, rand() % GAME_AREA_HEIGHT + 1);

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

		if(getPlayerEatFruit(&game.fruit)){
			while(isFruitOnSnake(game.fruit, &player_snake_head)){
				printf("Fruit on snake!\n");
				moveFruit(&game.fruit, rand() % GAME_AREA_WIDTH, rand() % GAME_AREA_HEIGHT);
			}
			printf("Fruit eaten!\n");
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

	renderFruit(&game.fruit);
	renderPlayer();

	SDL_SetRenderDrawColor(main_renderer, 127, 127, 127, 255);

	for(int i = 0; i <= GAME_AREA_HEIGHT; i++){
		for(int j = 0; j <= GAME_AREA_WIDTH; j++){
			SDL_Rect rect = {
				.x = j * 8,
				.y = i * 8,
				.w = 8,
				.h = 8,
			};

			if(i == 0 || i == GAME_AREA_HEIGHT){
				SDL_RenderFillRect(main_renderer, &rect);
			}

			if(j == 0 || j == GAME_AREA_WIDTH){
				SDL_RenderFillRect(main_renderer, &rect);
			}
		}
	}
	
	SDL_RenderPresent(main_renderer);
}
