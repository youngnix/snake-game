#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

static const unsigned int MAIN_WINDOW_WIDTH = 1280;
static const unsigned int MAIN_WINDOW_HEIGHT = 720;

extern SDL_Window* main_window;

int windowSetup(SDL_Window** window, const char* title, unsigned int width, unsigned int height);

#endif
