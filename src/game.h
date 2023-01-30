#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "food.h"
#include "keyboard.h"
#include "linked_list.h"
#include "player.h"
#include "renderer.h"
#include "snake.h"
#include "util.h"
#include "window.h"

#include <time.h>

#include <SDL2/SDL.h>
#include <stdbool.h>

extern const unsigned int GAME_AREA_WIDTH;
extern const unsigned int GAME_AREA_HEIGHT;

typedef struct {
	unsigned char is_running;
	LinkedListNode* food_head;
} Game;

extern Game game;

int gameSetup();

#endif
