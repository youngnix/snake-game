#include "game.h"
#include "renderer.h"
#include "window.h"

const unsigned int WINDOW_SCALE_MULTIPLIER = 32;

SDL_Window* window = { 0 };

int windowSetup(){
	window_width = GAME_AREA_WIDTH * WINDOW_SCALE_MULTIPLIER;
	window_height = GAME_AREA_HEIGHT * WINDOW_SCALE_MULTIPLIER;
	
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
	
	if(window == NULL){
		fprintf(stderr, "%s(window: %p, title: %s, width: %d, height: %d): %s\n", __func__, window, WINDOW_TITLE, window_width, window_height, SDL_GetError());
		return -1;
	}
	
	return 0;
}
