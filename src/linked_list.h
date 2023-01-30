#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode LinkedListNode;

typedef struct LinkedListNode {
	void* data;
	LinkedListNode* link;
} LinkedListNode;

LinkedListNode* createLinkedListNode(void* data);
int pushFrontLinkedListNode(LinkedListNode** head, void* data);
int pushBackLinkedListNode(LinkedListNode* head, void* data);
int popFrontLinkedListNode(LinkedListNode** head);
int popBackLinkedListNode(LinkedListNode* head);
int popLinkedListNode(LinkedListNode* head, LinkedListNode* node);
int getLinkedListNodeCount(LinkedListNode* head);
LinkedListNode* findPreviousLinkedListNode(LinkedListNode* head, LinkedListNode* node);
LinkedListNode* findLastLinkedListNode(LinkedListNode* head);
void freeLinkedList(LinkedListNode* head);

#endif
