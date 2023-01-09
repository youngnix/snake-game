#include "window.h"
#include "renderer.h"
#include "game.h"

SDL_Renderer* main_renderer;

int rendererSetup(SDL_Renderer** renderer, SDL_Window** window){
	*renderer = SDL_CreateRenderer(*window, -1, 0);
	
	if(*renderer == NULL){
		printf("Renderer error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}
