#include <stdio.h>
#include <stdlib.h>
#define SIZE 8 
int arr[] = { 34, 78, 12, 54, 89, 23, 77, 88 };
int sequential_search(int key) {
	int i;
	for (i = 0; i < SIZE; i++)
		if (arr[i] == key)
			return i; // Ž�� ����
	return -1; // Ž�� ����
}

int main() {
	int key, result;
	printf("�˻��� Ű ���� �Է��ϼ���: ");
	scanf("%d", &key);
	result = sequential_search(key);
	if (result == -1)
		printf("��Ҹ� ã�� ���߽��ϴ�.\n");
	else
		printf("��Ұ� �迭�� %d��° �ε����� �ֽ��ϴ�.\n", result);
	return 0;
}