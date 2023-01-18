#ifndef GAME_H
#define GAME_H

#include "fruit.h"
#include <SDL2/SDL.h>

extern const unsigned int GAME_AREA_WIDTH;
extern const unsigned int GAME_AREA_HEIGHT;

typedef struct {
	unsigned char is_running;
	Fruit fruit;
} Game;

static Game game;

int gameSetup();
static void gameBeginLoop();
int gameCleanUp();
static void gameRender();

#endif
