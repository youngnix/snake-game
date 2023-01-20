#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
	bool* pressed_input;
	bool* held_input;
	bool* released_input;
} Keyboard;

static Keyboard keyboard;

void keyboardSetup();
void clearKeyboard();
void eventKeyDown(SDL_Event* event);
void eventKeyUp(SDL_Event* event);
unsigned char getKeyPressed(SDL_Scancode scancode);
unsigned char getKeyReleased(SDL_Scancode scancode);
unsigned char getKeyHeld(SDL_Scancode scancode);
void keyboardCleanUp();

#endif
