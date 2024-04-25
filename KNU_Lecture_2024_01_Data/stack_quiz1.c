#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack {
	char data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack* s) {
	s->top = -1;
}

int is_full(Stack* s) {
	return s->top == MAX_STACK_SIZE;
}

int is_empty(Stack* s) {
	return s->top == -1;
}

char pop(Stack* s) {
	return s->data[s->top--];
}

void push(Stack* s, char c) {
	if (is_full(s)) {
		exit(1);
		return;
	}

	s->data[++s->top] = c;
}

int check_matching(const char* str) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	init_stack(s);
	char last;

	for (int i = 0; i < strlen(str); ++i) {
		char c = str[i];

		switch (c) {
		case '(': case '{': case '[':
			push(s, c);
			break;
		case ')': case '}': case ']':
			if (is_empty(s)) {
				return 0;
			}

			last = pop(s, c);
			if (last == '(' && c == ')') {
				continue;
			}
			if (last == '{' && c == '}') {
				continue;
			}
			if (last == '[' && c == ']') {
				continue;
			}
			return 0;
		}
	}

	return is_empty(s);
}

int main(void)
{
	char* p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1)
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;
}