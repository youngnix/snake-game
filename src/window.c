#include "game.h"
#include "renderer.h"
#include "window.h"

SDL_Window* main_window = { 0 };

int windowSetup(SDL_Window** window, const char* title, unsigned int width, unsigned int height){
	*window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if(*window == NULL){
		printf("Window error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}
