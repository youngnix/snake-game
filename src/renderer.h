#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

extern SDL_Renderer* renderer;

int rendererSetup();
void renderRectangle(int x, int y, int width, int height, unsigned int color);

#endif
