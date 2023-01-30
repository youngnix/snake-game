#include "linked_list.h"

static int handleInvalidLinkedListNode(LinkedListNode* node){
	if(node == NULL){
		fprintf(stderr, "(*node: %p): invalid node @ ", node);
		return -1;
	}
		
	return 0;
}

LinkedListNode* createLinkedListNode(void* data){
	LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	
	if(handleInvalidLinkedListNode(node) == -1){
		printf("%s\n", __func__);
		return NULL;
	}
	
	node->data = data;
	node->link = NULL;
		
	return node;
}

int pushFrontLinkedListNode(LinkedListNode** head, void* data){
	if(handleInvalidLinkedListNode(*head) == -1){
		printf("%s\n", __func__);
		return -1;
	}
		
	LinkedListNode* new_head = createLinkedListNode(data);
		
	if(handleInvalidLinkedListNode(new_head) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	new_head->link = *head;
	*head = new_head;

	return 0;
}

int pushBackLinkedListNode(LinkedListNode* head, void* data){
	if(handleInvalidLinkedListNode(head) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	LinkedListNode* new_node = createLinkedListNode(data);
    
	findLastLinkedListNode(head)->link = new_node;
	
	return 0;
}

int popBackLinkedListNode(LinkedListNode* head){
	if(handleInvalidLinkedListNode(head) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	LinkedListNode* last_node = findLastLinkedListNode(head);

	if(handleInvalidLinkedListNode(last_node) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	popLinkedListNode(head, last_node);

	return 0;
}

LinkedListNode* findPreviousLinkedListNode(LinkedListNode* head, LinkedListNode* node){
	if(handleInvalidLinkedListNode(head) == -1){
		printf("%s\n", __func__);
		return NULL;
	}

	if(handleInvalidLinkedListNode(node) == -1){
		printf("%s\n", __func__);
		return NULL;
	}

	if(node == head)
		return head;

	for(LinkedListNode* ptr = head; ptr != NULL; ptr = ptr->link){
		if(ptr->link == node)
			return ptr;
	}

	fprintf(stderr, "%s(*head: %p): couldn't find node.\n", __func__, head);
	return NULL;
}

LinkedListNode* findLastLinkedListNode(LinkedListNode* head){
	if(handleInvalidLinkedListNode(head) == -1){
		printf("%s\n", __func__);
		return NULL;
	}

	for(LinkedListNode* ptr = head; ptr != NULL; ptr = ptr->link){
		if(ptr->link == NULL)
			return ptr;
	}
	
	fprintf(stderr, "%s(*head: %p): couldn't find last node.\n", __func__, head);
	return NULL;
}

int popLinkedListNode(LinkedListNode* head, LinkedListNode* node){
	if(handleInvalidLinkedListNode(head) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	if(handleInvalidLinkedListNode(node) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	LinkedListNode* previous_node = findPreviousLinkedListNode(head, node);

	if(handleInvalidLinkedListNode(previous_node) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	previous_node->link = node->link;

	if(node->data != NULL)
		free(node->data);

	free(node);
	
	return 0;
}

void freeLinkedList(LinkedListNode* head){
	if(handleInvalidLinkedListNode(head)){
		printf("%s\n", __func__);
		return;
	}

	for(;;){
		if(popFrontLinkedListNode(&head) == -1)
			break;
	}
}

int popFrontLinkedListNode(LinkedListNode** head){
	if(handleInvalidLinkedListNode(*head) == -1){
		printf("%s\n", __func__);
		return -1;
	}

	LinkedListNode* head_link = (*head)->link;

	popLinkedListNode(*head, *head);
	
	*head = head_link;

	return 0;
}
