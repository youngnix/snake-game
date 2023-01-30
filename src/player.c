#include "player.h"
#include "game.h"
#include "keyboard.h"
#include "linked_list.h"
#include "snake.h"
#include "renderer.h"
#include "window.h"

const static unsigned int MINIMUM_CYCLE_COUNT = 10;

LinkedListNode* player_head = NULL;

void updatePlayer(){
	if(player_head == NULL)
		return;

	static int tick_counter = 0;

	static unsigned char next_direction = 0;

	if(getPlayerDirection() != ((SnakeSegment*)player_head->data)->direction)
		next_direction = getPlayerDirection();

	if(tick_counter >= MINIMUM_CYCLE_COUNT){
		tick_counter = 0;

		player_head->data = createSnakeSegment(((SnakeSegment*)player_head->data)->x, ((SnakeSegment*)player_head->data)->y, next_direction);

		movePlayer();
		playerEatItself();
	}
	
	tick_counter++;
}

void renderPlayer(){
	if(player_head == NULL)
		return;
	
	for(LinkedListNode* ptr = player_head; ptr != NULL; ptr = ptr->link)
		renderSnakeSegment(ptr->data);
}

unsigned char getPlayerDirection(){
	SnakeSegment* head_data = player_head->data;

	if(head_data->direction != 'r' && getKeyPressed(SDL_SCANCODE_LEFT))
		return 'l';

	if(head_data->direction != 'l' && getKeyPressed(SDL_SCANCODE_RIGHT))
		return 'r';

	if(head_data->direction != 'u' && getKeyPressed(SDL_SCANCODE_DOWN))
		return 'd';
	
	if(head_data->direction != 'd' && getKeyPressed(SDL_SCANCODE_UP))
		return 'u';

	return head_data->direction;
}

void movePlayer(){
	SnakeSegment* segment = player_head->data;

	switch(segment->direction){
	case 'u':
		pushFrontLinkedListNode(&player_head, createSnakeSegment(segment->x, (segment->y - 1 + GAME_AREA_HEIGHT) % GAME_AREA_HEIGHT, segment->direction));
		break;
	case 'l':
		pushFrontLinkedListNode(&player_head, createSnakeSegment((segment->x - 1 + GAME_AREA_WIDTH) % GAME_AREA_WIDTH, segment->y, segment->direction));
		break;
	case 'd':
		pushFrontLinkedListNode(&player_head, createSnakeSegment(segment->x, (segment->y + 1 + GAME_AREA_HEIGHT) % GAME_AREA_HEIGHT, segment->direction));
		break;
	case 'r':
		pushFrontLinkedListNode(&player_head, createSnakeSegment((segment->x + 1 + GAME_AREA_WIDTH) % GAME_AREA_WIDTH, segment->y, segment->direction));
		break;
	default:
		pushFrontLinkedListNode(&player_head, createSnakeSegment(segment->x, segment->y, segment->direction));
		break;
	}
}

void playerEatItself(){
	SnakeSegment* player_data = player_head->data;

	for(LinkedListNode* ptr = player_head->link; ptr != NULL; ptr = ptr->link){
		SnakeSegment* ptr_data = ptr->data;
		
		if(ptr_data->x != player_data->x
		   || ptr_data->y != player_data->y)
			continue;
		
		for(;;){
			LinkedListNode* last_node = findLastLinkedListNode(player_head);

			popLinkedListNode(player_head, last_node);

			if(last_node == ptr)
				return;
		}
	}
	
	for(LinkedListNode* food_ptr = game.food_head; food_ptr != NULL; food_ptr = food_ptr->link){
		if(!isSnakeSegmentOnFood(player_head->data, food_ptr->data))
			popBackLinkedListNode(player_head);
	}
}
