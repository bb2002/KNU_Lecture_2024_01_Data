#include <stdio.h>
#include <stdlib.h>

#define SIZE 8 
#define INDEX_TABLE_SIZE 4 

typedef struct IndexTable {
	int index;
	int start;
} IndexTable;

int arr[] = { 12, 23, 34, 54, 77, 78, 88, 89 };
int list[] = { 12, 23, 34, 54, 77, 78, 88, 89 };

IndexTable index_table[] = {
	{12, 0},
	{34, 2},
	{77, 4},
	{88, 6}
};

int indexed_sequential_search(int key) {
	int i;
	// ���� ���̺��� �̿��Ͽ� ������ ���� ã��
	for (i = 0; i < INDEX_TABLE_SIZE - 1; i++) {
		if (key < index_table[i + 1].index) {
			break;
		}
	}
	// �ش� ���ǿ��� ���� �˻� ����
	for (int j = index_table[i].start; j < SIZE && (j < index_table[i + 1].start ||
		i == INDEX_TABLE_SIZE - 1); j++) {
		if (arr[j] == key) {
			return j; // Ž�� ����
		}
	}
	return -1;
}

int interpol_search(int key, int n)
{
	int low, high, j;
	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low])
			* (high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;
	}
	if (list[low] == key) return(low); // Ž������
	else return -1; // Ž������
}

int main() {
	int key, result;
	printf("�˻��� Ű ���� �Է��ϼ���: ");
	scanf("%d", &key);
	result = indexed_sequential_search(key);
	if (result == -1)
		printf("��Ҹ� ã�� ���߽��ϴ�.\n");
	else
		printf("��Ұ� �迭�� %d��° �ε����� �ֽ��ϴ�.\n", result);
	return 0;
}