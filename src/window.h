#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

extern SDL_Window* main_window;

int windowSetup(SDL_Window** window, const char* title, unsigned int width, unsigned int height);

#endif
