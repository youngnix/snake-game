#ifndef food_H
#define food_H

#include <SDL2/SDL_image.h>

typedef struct Food Food;

typedef struct Food {
	int x, y;
	SDL_Texture* texture;
} Food;

Food* createFood(int x, int y, SDL_Texture* texture);
void renderFood(Food* food);

#endif
