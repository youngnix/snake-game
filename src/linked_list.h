#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedListNode LinkedListNode;

typedef struct LinkedListNode {
	void* data;
	LinkedListNode* link;
} LinkedListNode;

LinkedListNode* createLinkedListNode(void* data);
void addLinkedListHeadNode(LinkedListNode** linked_list_head_node, void* data);
void addLinkedListTailNode(LinkedListNode** linked_list_head_node, void* data);
int getLinkedListNodeCount(LinkedListNode** linked_list_head_node);
LinkedListNode* findPreviousLinkedListNode(LinkedListNode** linked_list_head_node, LinkedListNode** linked_list_node);
LinkedListNode* findLinkedListTailNode(LinkedListNode** linked_list_head_node);
void removeLinkedListNode(LinkedListNode** linked_list_head_node, LinkedListNode** linked_list_node);
LinkedListNode* findRandomLinkedListNode(LinkedListNode** linked_list_head_node);

#endif
