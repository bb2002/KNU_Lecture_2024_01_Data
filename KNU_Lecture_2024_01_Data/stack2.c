#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct StackType {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* type) {
	type->top = -1;
}

int is_empty(StackType* stack) {
	return stack->top == -1;
}

int is_full(StackType* stack) {
	return stack->top == MAX_STACK_SIZE - 1;
}

void push(StackType* stack, element data) {
	if (is_full(stack)) {
		printf("stack is full");
		return;
	}
	stack->data[++stack->top] = data;
}

element pop(StackType* stack) {
	if (is_empty(stack)) {
		printf("stack is empty");
		return;
	}
	return stack->data[stack->top--];
}

int main(void)
{
	StackType* s;
	s = (StackType*)malloc(sizeof(StackType));
	init(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	free(s);
}