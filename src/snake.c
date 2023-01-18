#include "snake.h"
#include <stdlib.h>

int snakeSetup(SnakeSegment** snake_head){
	*snake_head = (SnakeSegment*)malloc(sizeof(SnakeSegment));

	(*snake_head)->segment_link = NULL;

	(*snake_head)->x = 0;
	(*snake_head)->y = 0;

	return 0;
}

void addSnakeSegment(SnakeSegment** snake_head){
	SnakeSegment* last_snake_segment = findLastSnakeSegment(snake_head);
	SnakeSegment* previous_snake_segment = NULL;

	last_snake_segment->segment_link = (SnakeSegment*)malloc(sizeof(SnakeSegment));

	last_snake_segment = last_snake_segment->segment_link;

	previous_snake_segment = findPreviousSnakeSegment(snake_head, &last_snake_segment);

	last_snake_segment->segment_link = NULL;
	last_snake_segment->x = previous_snake_segment->x;
	last_snake_segment->y = previous_snake_segment->y;
}

unsigned int getSnakeSegmentCount(SnakeSegment** snake_head){
	unsigned int segment_count = 0;

	for(SnakeSegment* segment_pointer = *snake_head; segment_pointer != NULL; segment_pointer = segment_pointer->segment_link){
		segment_count++;
	}

	return segment_count;
}

SnakeSegment* findPreviousSnakeSegment(SnakeSegment** snake_head, SnakeSegment** snake_segment){
	if(*snake_segment == *snake_head) return *snake_head;

	for(SnakeSegment* segment_pointer = *snake_head; segment_pointer != NULL; segment_pointer = segment_pointer->segment_link){
		if(segment_pointer->segment_link == *snake_segment){
			return segment_pointer;
		}
	}

	return NULL;
}


SnakeSegment* findLastSnakeSegment(SnakeSegment** snake_head){
	if(snake_head == NULL) return NULL;

	for(SnakeSegment* segment_pointer = *snake_head; segment_pointer != NULL; segment_pointer = segment_pointer->segment_link){
		if(segment_pointer->segment_link == NULL){
			return segment_pointer;
		}
	}

	return *snake_head;
}

void freeSnake(SnakeSegment** snake_head){
	for(SnakeSegment* segment_pointer = findLastSnakeSegment(snake_head); segment_pointer != *snake_head; segment_pointer = findPreviousSnakeSegment(snake_head, &segment_pointer)){
		free(segment_pointer);
	}

	free(*snake_head);
}
