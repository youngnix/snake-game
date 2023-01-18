#include "keyboard.h"

#include <SDL2/SDL.h>

static Keyboard keyboard = { NULL, NULL, NULL };

void keyboardSetup(){
	keyboard.held_input = (unsigned char*)malloc(sizeof(unsigned char) * 512);
	keyboard.pressed_input = (unsigned char*)malloc(sizeof(unsigned char) * 512);
	keyboard.released_input = (unsigned char*)malloc(sizeof(unsigned char) * 512);
}

void clearKeyboard(){
	for(int i = 0; i < 512; i++){
		keyboard.pressed_input[i] = 0;
		keyboard.released_input[i] = 0;
	}
}

void eventKeyDown(SDL_Event* event){
	keyboard.held_input[event->key.keysym.scancode] = 1;
	keyboard.pressed_input[event->key.keysym.scancode] = 1;
}

void eventKeyUp(SDL_Event* event){
	keyboard.released_input[event->key.keysym.scancode] = 1;
	keyboard.held_input[event->key.keysym.scancode] = 0;
}

unsigned char getKeyPressed(SDL_Scancode scancode){
	return keyboard.pressed_input[scancode];
}

unsigned char getKeyReleased(SDL_Scancode scancode){
	return keyboard.released_input[scancode];
}

unsigned char getKeyHeld(SDL_Scancode scancode){
	return keyboard.held_input[scancode];
}