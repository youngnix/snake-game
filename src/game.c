#include "renderer.h"
#include "window.h"
#include "game.h"

int gameSetup(){
	windowSetup(root_window, "Title", 1280, 720);
	rendererSetup(root_renderer, root_window);

	return 0;
}

int gameCleanUp(){
	SDL_DestroyRenderer(root_renderer);
	SDL_DestroyWindow(root_window);
	SDL_Quit();

	return 0;
}
