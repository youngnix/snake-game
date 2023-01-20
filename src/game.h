#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "linked_list.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <dirent.h>

extern const unsigned int GAME_AREA_WIDTH;
extern const unsigned int GAME_AREA_HEIGHT;

typedef struct {
	bool victory;
} GameState;

typedef struct {
	GameState state;
	unsigned char is_running;
	LinkedListNode* food_head;
	LinkedListNode* food_texture_head;
} Game;

extern Game game;

int gameSetup();
static void gameBeginLoop();
int gameCleanUp();
static void gameRender();

#endif
