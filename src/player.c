#include "player.h"
#include "game.h"
#include "keyboard.h"
#include "linked_list.h"
#include "snake.h"
#include "renderer.h"

const static unsigned int MINIMUM_CYCLE_COUNT = 10;

LinkedListNode* player_head;

void updatePlayer(){
	static int tick_counter = 0;

	updatePlayerDirection();

	if(tick_counter >= MINIMUM_CYCLE_COUNT){
		tick_counter = 0;

		movePlayer();
	}

	tick_counter++;
}

void renderPlayer(){
	SnakeData* snake_data;
	for(LinkedListNode* ptr = player_head->link; ptr != NULL; ptr = ptr->link){
		snake_data = (SnakeData*)ptr->data;

		renderRectangle(snake_data->x * 16 + 1, snake_data->y * 16 + 1, 14, 14, 0xFFFFFFFF);
	}

	snake_data = (SnakeData*)player_head->data;

	renderRectangle(snake_data->x * 16 + 1, snake_data->y * 16 + 1, 14, 14, 0x00FF00FF);
}

void updatePlayerDirection(){
	if(((SnakeData*)player_head->data)->direction != 'r' && getKeyPressed(SDL_SCANCODE_LEFT)){
		((SnakeData*)player_head->data)->direction = 'l';
	}

	if(((SnakeData*)player_head->data)->direction != 'l' && getKeyPressed(SDL_SCANCODE_RIGHT)){
		((SnakeData*)player_head->data)->direction = 'r';
	}

	if(((SnakeData*)player_head->data)->direction != 'u' && getKeyPressed(SDL_SCANCODE_DOWN)){
		((SnakeData*)player_head->data)->direction = 'd';
	}

	if(((SnakeData*)player_head->data)->direction != 'd' && getKeyPressed(SDL_SCANCODE_UP)){
		((SnakeData*)player_head->data)->direction = 'u';
	}
}

int didPlayerEatFood(){
	for(LinkedListNode* ptr = game.food_head; ptr != NULL; ptr = ptr->link){
		if(isFoodOnSnake(&player_head, ptr->data)){
			return 1;
		}
	}

	return 0;
}

void movePlayer(){
	SnakeData* player_data = (SnakeData*)player_head->data;
	LinkedListNode* player_tail = findLinkedListTailNode(&player_head);

	switch(player_data->direction){
		case 'u':
			addLinkedListHeadNode(&player_head, createSnakeData(player_data->x, player_data->y - 1, player_data->direction));
		break;
		case 'l':
			addLinkedListHeadNode(&player_head, createSnakeData(player_data->x - 1, player_data->y, player_data->direction));
		break;
		case 'd':
			addLinkedListHeadNode(&player_head, createSnakeData(player_data->x, player_data->y + 1, player_data->direction));
		break;
		case 'r':
			addLinkedListHeadNode(&player_head, createSnakeData(player_data->x + 1, player_data->y, player_data->direction));
		break;
		default:
			addLinkedListHeadNode(&player_head, createSnakeData(player_data->x, player_data->y, player_data->direction));
		break;
	}

	if(!didPlayerEatFood()){
		removeLinkedListNode(&player_head, &player_tail);
	}
}
