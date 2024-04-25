#include <stdio.h.>
#include <stdlib.h>

typedef int Element;
typedef struct StackNode {
	Element data;
	struct StackNode* next;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init(LinkedStackType* stack) {
	stack->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}

void print_stack(LinkedStackType* s) {
	for (StackNode* node = s->top; node != NULL; node = node->next) {
		printf("%d -> ", node->data);
	}
	printf("NULL\n");
}

Element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		printf("STACK IS EMPTY");
		exit(1);
	}
	else {
		StackNode* tmp = s->top;
		Element data = tmp->data;
		s->top = tmp->next;
		free(tmp);
		return data;
	}
}

void push(LinkedStackType* s, Element item) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = item;
	node->next = s->top;
	s->top = node;
}

int main(void)
{
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}