#include "game.h"
#include "renderer.h"
#include "window.h"

Game game = { 0 };

int gameSetup(){
	game.is_running = 1;

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		printf("SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	windowSetup(&main_window, "Title", 1280, 720);
	rendererSetup(&main_renderer, &main_window);

	gameBeginLoop();

	gameCleanUp();
	return 0;
}

int gameCleanUp(){
	SDL_DestroyRenderer(main_renderer);
	SDL_DestroyWindow(main_window);
	SDL_Quit();

	return 0;
}

void gameBeginLoop(){
	SDL_Event event;
	while(game.is_running == 1){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					game.is_running = 0;
				break;
				default:
				break;
			}
		}
		SDL_RenderClear(main_renderer);

		SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);

		SDL_RenderClear(main_renderer);
	}
}
