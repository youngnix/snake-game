#include "game.h"
#include "food.h"
#include "linked_list.h"
#include "player.h"
#include "snake.h"

const unsigned int GAME_AREA_WIDTH = 16;
const unsigned int GAME_AREA_HEIGHT = 12;

Game game = { 0 };

static void gameBeginLoop();
static int gameCleanUp();
static void gameRender();
static void gameUpdate();
static void updateFood();

int gameSetup(){
	game.is_running = 1;

	srand(time(NULL));

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
		return -1;
	}

	windowSetup();
	rendererSetup();
	keyboardSetup();

	player_head = createLinkedListNode(createSnakeSegment(GAME_AREA_WIDTH / 2, GAME_AREA_HEIGHT / 2, 0));
	game.food_head = createLinkedListNode(createFood(rand() % GAME_AREA_WIDTH, rand() % GAME_AREA_HEIGHT, NULL));

	gameBeginLoop();

	gameCleanUp();
	return 0;
}

static void gameBeginLoop(){
	SDL_Event event;
	while(game.is_running == 1){
		clearKeyboard();

		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_KEYUP:
				eventKeyUp(&event);
				break;
			case SDL_KEYDOWN:
				if(!event.key.repeat)
					eventKeyDown(&event);
				break;
			case SDL_QUIT:
				game.is_running = 0;
				break;
			default:
				break;
			}
		}

		if(getKeyPressed(SDL_SCANCODE_Q))
			game.is_running = 0;

		gameUpdate();
		gameRender();
	}
}

static void updateFood(){
	if(game.food_head == NULL)
		return;
	
	for(LinkedListNode* segment_ptr = player_head; segment_ptr != NULL; segment_ptr = segment_ptr->link){
		for(LinkedListNode* food_ptr = game.food_head; food_ptr != NULL; food_ptr = food_ptr->link){
			if(!isSnakeSegmentOnFood(segment_ptr->data, food_ptr->data))
				break;

			food_ptr->data = createFood(rand() % GAME_AREA_WIDTH, rand() % GAME_AREA_HEIGHT, NULL);
		}
	}
}

static void gameUpdate(){
	updatePlayer();
	updateFood();
}

static void gameRender(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);

	renderPlayer();

	for(LinkedListNode* ptr = game.food_head; ptr != NULL; ptr = ptr->link){
		if(ptr == NULL)
			break;
		
		renderFood(ptr->data);
	}

	SDL_RenderPresent(renderer);
}

static int gameCleanUp(){
	freeLinkedList(player_head);
	freeLinkedList(game.food_head);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
