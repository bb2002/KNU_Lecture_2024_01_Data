#include <stdio.h>
#include <stdlib.h>
#define SIZE 8 
int arr[] = { 12, 23, 34, 54, 77, 78, 88, 89 };

int binary_search(int key) {
	int middle;
	int low = 0;
	int high = SIZE - 1;
	while (low <= high) { // 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		if (key == arr[middle])
			return middle; // 탐색 성공
		else if (key > arr[middle])
			low = middle + 1; // 오른쪽 부분리스트 탐색
		else
			high = middle - 1; // 왼쪽 부분리스트 탐색
	}
	return -1; // 탐색 실패
}

int main() {
	int key, result;
	printf("검색할 키 값을 입력하세요: ");
	scanf("%d", &key);
	result = binary_search(key);
	if (result == -1)
		printf("요소를 찾지 못했습니다.\n");
	else
		printf("요소가 배열의 %d번째 인덱스에 있습니다.\n", result);
	return 0;
}