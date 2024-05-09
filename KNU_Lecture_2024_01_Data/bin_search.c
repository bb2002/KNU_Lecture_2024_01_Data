#include <stdio.h>
#include <stdlib.h>
#define SIZE 8 
int arr[] = { 12, 23, 34, 54, 77, 78, 88, 89 };

int binary_search(int key) {
	int middle;
	int low = 0;
	int high = SIZE - 1;
	while (low <= high) { // ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		if (key == arr[middle])
			return middle; // Ž�� ����
		else if (key > arr[middle])
			low = middle + 1; // ������ �κи���Ʈ Ž��
		else
			high = middle - 1; // ���� �κи���Ʈ Ž��
	}
	return -1; // Ž�� ����
}

int main() {
	int key, result;
	printf("�˻��� Ű ���� �Է��ϼ���: ");
	scanf("%d", &key);
	result = binary_search(key);
	if (result == -1)
		printf("��Ҹ� ã�� ���߽��ϴ�.\n");
	else
		printf("��Ұ� �迭�� %d��° �ε����� �ֽ��ϴ�.\n", result);
	return 0;
}