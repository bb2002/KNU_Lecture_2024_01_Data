#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_STACK_SIZE - 1;
}

element push(element item) {
	if (is_full()) {
		printf("stack is full");
		return;
	}

	stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		printf("stack is empty");
		return;
	}

	return stack[top--];
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}
