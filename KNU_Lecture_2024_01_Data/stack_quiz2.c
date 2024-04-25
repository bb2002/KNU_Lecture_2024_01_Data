#include <stdio.h>
#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char c) {
	stack[++top] = c;
}

char pop() {
	return stack[top--];
}

int eval(const char* str) {
	for (int i = 0; i < strlen(str); ++i) {
		char c = str[i];

		if (c != '+' && c != '-' && c != '*' && c != '/') {
			// �׸��� �� �������̸�
			push(c - '0');
		}
		else {
			int second = pop();
			int first = pop();

			int result = 0;
			switch (c) {
			case '+':
				push(first + second);
				break;
			case '-':
				push(first - second);
				break;
			case '*':
				push(first * second);
				break;
			case '/':
				push(first / second);
				break;
			}
		}
	}

	return pop();
}

int main(void)
{
	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}
