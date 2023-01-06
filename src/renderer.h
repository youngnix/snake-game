#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

extern SDL_Renderer* root_renderer;

int rendererSetup(SDL_Renderer* renderer, SDL_Window* window);

#endif
