#include "game.h"
#include "renderer.h"
#include "window.h"
#include <SDL2/SDL_render.h>

SDL_Renderer* main_renderer = { 0 };

int rendererSetup(SDL_Renderer** renderer, SDL_Window** window){
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	SDL_RenderSetLogicalSize(main_renderer, 320, 180);
	
	if(*renderer == NULL){
		printf("Renderer error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}

void renderRectangle(int x, int y, int width, int height, unsigned int color){
	if(!x){
		fprintf(stderr, "renderRectangle(): Invalid argument \"x\"!\n");
		return;
	}

	if(!y){
		fprintf(stderr, "renderRectangle(): Invalid argument \"y\"!\n");
		return;
	}

	if(!width){
		fprintf(stderr, "renderRectangle(): Invalid argument \"width\"!\n");
		return;
	}

	if(!height){
		fprintf(stderr, "renderRectangle(): Invalid argument \"height\"!\n");
		return;
	}

	SDL_Rect rectangle = {
		.x = x,
		.y = y,
		.w = width,
		.h = height,
	};

	SDL_SetRenderDrawColor(main_renderer, (color >> 24) & 0x000000FF, (color >> 16) & 0x000000FF, (color >> 8) & 0x000000FF, (color >> 0) & 0x000000FF);
	SDL_RenderFillRect(main_renderer, &rectangle);
}
