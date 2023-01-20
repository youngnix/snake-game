#include "linked_list.h"
#include "snake.h"
#include <stdlib.h>

LinkedListNode* createLinkedListNode(void* data){
	LinkedListNode* linked_list_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	linked_list_node->data = data;
	linked_list_node->link = NULL;

	return linked_list_node;
}

void addLinkedListHeadNode(LinkedListNode** linked_list_head_node, void* data){
	LinkedListNode* new_linked_list_head_node = createLinkedListNode(data);

	new_linked_list_head_node->link = *linked_list_head_node;

	*linked_list_head_node = new_linked_list_head_node;
}

void addLinkedListTailNode(LinkedListNode** linked_list_head_node, void* data){
	if(*linked_list_head_node == NULL){
		*linked_list_head_node = createLinkedListNode(data);
		return;
	}

	findLinkedListTailNode(linked_list_head_node)->link = createLinkedListNode(data);
}

int getLinkedListNodeCount(LinkedListNode** linked_list_head_node){
	unsigned int node_count = 0;

	for(LinkedListNode* ptr = *linked_list_head_node; ptr != NULL; ptr = ptr->link){
		node_count++;
	}

	return node_count;
}

LinkedListNode* findPreviousLinkedListNode(LinkedListNode** linked_list_head_node, LinkedListNode** linked_list_node){
	if(*linked_list_node == *linked_list_head_node) return *linked_list_head_node;

	for(LinkedListNode* ptr = *linked_list_head_node; ptr != NULL; ptr = ptr->link){
		if(ptr->link == *linked_list_node){
			return ptr;
		}
	}

	return NULL;
}


LinkedListNode* findLinkedListTailNode(LinkedListNode** linked_list_head_node){
	if(linked_list_head_node == NULL) return NULL;

	for(LinkedListNode* ptr = *linked_list_head_node; ptr != NULL; ptr = ptr->link){
		if(ptr->link == NULL){
			return ptr;
		}
	}

	return NULL;
}

void removeLinkedListNode(LinkedListNode** linked_list_head_node, LinkedListNode** linked_list_node){
	LinkedListNode* previous_linked_list_node = findPreviousLinkedListNode(linked_list_head_node, linked_list_node);
	previous_linked_list_node->link = (*linked_list_node)->link;

	if((*linked_list_node)->data != NULL) free((*linked_list_node)->data);

	free(*linked_list_node);
}

LinkedListNode* findRandomLinkedListNode(LinkedListNode** linked_list_head_node){
	int random_number = rand() % getLinkedListNodeCount(linked_list_head_node);
	int node_counter = 0;

	if(random_number == 0){
		return *linked_list_head_node;
	}

	if(random_number == getLinkedListNodeCount(linked_list_head_node)){
		return findLinkedListTailNode(linked_list_head_node);
	}

	for(LinkedListNode* ptr = *linked_list_head_node;; ptr = ptr->link){
		if(node_counter == random_number){
			return ptr;
		}
		
		node_counter++;
	}

	return NULL;
}
