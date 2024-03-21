#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define SIZE 10

int main() {
	int* p;
	int size;

	printf("size: ");
	scanf("%d", &size);

	p = (int*)malloc(size * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "Out Of Memoery");
		return -1;
	}

	for (int i = 0; i < size; ++i) {
		p[i] = i;
	}

	for (int i = 0; i < size; ++i) {
		printf("%d ", p[i]);
	}

	free(p);
	return 0;
}