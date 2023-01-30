#include "game.h"
#include "renderer.h"
#include "window.h"
#include <SDL2/SDL_render.h>

SDL_Renderer* renderer = { 0 };

int rendererSetup(){
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	
	if(renderer == NULL){
		printf("Renderer error: %s\n", SDL_GetError());
		return -1;
	}

	return 0;
}

void renderRectangle(int x, int y, int width, int height, unsigned int color){
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

	SDL_SetRenderDrawColor(renderer, (color >> 24) & 0x000000FF, (color >> 16) & 0x000000FF, (color >> 8) & 0x000000FF, (color >> 0) & 0x000000FF);
	SDL_RenderFillRect(renderer, &rectangle);
}
