#include "game.h"
#include "renderer.h"
#include "window.h"
#include <SDL2/SDL_render.h>

SDL_Renderer* main_renderer = { 0 };

int rendererSetup(SDL_Renderer** renderer, SDL_Window** window){
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderSetLogicalSize(main_renderer, 320, 180);
	
	if(*renderer == NULL){
		printf("Renderer error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}
