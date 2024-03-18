#include<stdio.h>

int fact(int a) {
	if (a <= 1) {
		return 1;
	}

	return a * fact(a - 1);
}

int main() {
	printf("5! = %d", fact(5));
}