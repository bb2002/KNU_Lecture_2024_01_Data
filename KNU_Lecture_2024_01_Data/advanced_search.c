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
	// 색인 테이블을 이용하여 적절한 섹션 찾기
	for (i = 0; i < INDEX_TABLE_SIZE - 1; i++) {
		if (key < index_table[i + 1].index) {
			break;
		}
	}
	// 해당 섹션에서 선형 검색 수행
	for (int j = index_table[i].start; j < SIZE && (j < index_table[i + 1].start ||
		i == INDEX_TABLE_SIZE - 1); j++) {
		if (arr[j] == key) {
			return j; // 탐색 성공
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
	if (list[low] == key) return(low); // 탐색성공
	else return -1; // 탐색실패
}

int main() {
	int key, result;
	printf("검색할 키 값을 입력하세요: ");
	scanf("%d", &key);
	result = indexed_sequential_search(key);
	if (result == -1)
		printf("요소를 찾지 못했습니다.\n");
	else
		printf("요소가 배열의 %d번째 인덱스에 있습니다.\n", result);
	return 0;
}