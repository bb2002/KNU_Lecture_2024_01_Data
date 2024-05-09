#include <stdio.h>
#include <stdlib.h>
#define SIZE 8 
int arr[] = { 34, 78, 12, 54, 89, 23, 77, 88 };
int sequential_search(int key) {
	int i;
	for (i = 0; i < SIZE; i++)
		if (arr[i] == key)
			return i; // 탐색 성공
	return -1; // 탐색 실패
}

int main() {
	int key, result;
	printf("검색할 키 값을 입력하세요: ");
	scanf("%d", &key);
	result = sequential_search(key);
	if (result == -1)
		printf("요소를 찾지 못했습니다.\n");
	else
		printf("요소가 배열의 %d번째 인덱스에 있습니다.\n", result);
	return 0;
}