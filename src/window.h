#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

static unsigned int window_width = 1280;
static unsigned int window_height = 720;
extern const unsigned int WINDOW_SCALE_MULTIPLIER;
static const char WINDOW_TITLE[] = "Title";

extern SDL_Window* window;

int windowSetup();

#endif
