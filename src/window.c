#include "game.h"
#include "window.h"
#include "renderer.h"

SDL_Window* root_window;

int windowSetup(SDL_Window* window, const char* title, unsigned int width, unsigned int height){
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if(window == (void*)0){
		printf("Window error: %s\n", SDL_GetError());
		gameCleanUp();
		SDL_Quit();
		return 1;
	}

	return 0;
}
