#include <stdlib.h>
#include <stdio.h>

typedef char Element;

typedef struct StackNode {
	Element data;
	struct StackNode* next;
} StackNode;

typedef struct LinkedStackHead {
	StackNode* node;
} LinkedStackHead;

void init_stack(LinkedStackHead* head) {
	head->node = NULL;
}

void push(LinkedStackHead* head, Element data) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->next = head->node;
	head->node = node;
}

Element pop(LinkedStackHead* head) {
	StackNode* node = head->node;
	Element data = node->data;
	head->node = node->next;
	free(node);
	return data;
}

Element peek(LinkedStackHead* head) {
	Element data = head->node->data;
	return data;
}

// Èûµé´Ù