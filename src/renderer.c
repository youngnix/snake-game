#include "renderer.h"
#include "game.h"
#include <SDL2/SDL_render.h>

SDL_Renderer* root_renderer;

int rendererSetup(SDL_Renderer* renderer, SDL_Window* window){
	renderer = SDL_CreateRenderer(window, -1, 0);

	if(renderer == (void*)0){
		printf("Renderer error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}
