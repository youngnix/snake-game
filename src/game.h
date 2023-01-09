#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct {
	unsigned char is_running;
} Game;

extern Game game;

int gameSetup();
int gameCleanUp();
void gameBeginLoop();

#endif
