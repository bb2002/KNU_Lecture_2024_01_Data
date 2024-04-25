#include <stdio.h>

void hanoi(int tower, char start, char end, char tmp) {
	if (tower == 1) {
		printf("���� 1�� %c -> %c �� �ű�\n", start, end);
	}
	else {
		hanoi(tower - 1, start, tmp, end);
		printf("���� %d�� %c -> %c�� �ű�\n", tower, start, end);
		hanoi(tower - 1, tmp, end, start);
	}
}







































void hanoi2(int size, char start, char tmp, char end) {
	if (size == 1) {
		printf("���� 1�� %c -> %c�� �ű�\n", start, end);
	}
	else {
		hanoi2(size - 1, start, end, tmp);
		printf("���� %d�� %c -> %c�� �ű�\n", size, start, end);
		hanoi2(size - 1, tmp, start, end);
	}
}

int main() {
	hanoi(3, 'A', 'C', 'B');
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=\n");
	hanoi2(3, 'A', 'B', 'C');
}