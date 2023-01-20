#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

typedef struct {
	unsigned char* pressed_input;
	unsigned char* held_input;
	unsigned char* released_input;
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
