#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

extern SDL_Renderer* main_renderer;

int rendererSetup(SDL_Renderer** renderer, SDL_Window** window);
void renderRectangle(int x, int y, int width, int height, unsigned int color);

#endif
