#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}


int main() {
	int infinity = 99999;
	int problem_num = 0;
	scanf("%d", &problem_num);
	for (int problem = 0; problem < problem_num; ++problem) {
		int query_num = 0;
		StackType min_stack;
		StackType max_stack;
		scanf("%d", &query_num);
		init_stack(&min_stack);
		init_stack(&max_stack);
		push(&min_stack, infinity);
		push(&max_stack, -infinity);

		for (int query = 0; query < query_num; ++query) {
			int input1, input2, new_block = 0;	
			scanf("%d", &input1);
			switch (input1) {
			case 1:
				scanf("%d", &input2);
				new_block = input2;
				if (min_stack.data[min_stack.top] > new_block) {
					push(&min_stack, new_block);
				}
				else {
					push(&min_stack, min_stack.data[min_stack.top]);
				}
				if (max_stack.data[max_stack.top] < new_block) {
					push(&max_stack, new_block);
				}
				else {
					push(&max_stack, max_stack.data[max_stack.top]);
				}
				printf("%d %d\n", min_stack.data[min_stack.top], max_stack.data[max_stack.top]);
				break;
			case 2:
				if (min_stack.top != infinity) {
					pop(&min_stack);
				}
				if (max_stack.top != -infinity) {
					pop(&max_stack);
				}
				break;
			}
		}
	}

	return 0;
}