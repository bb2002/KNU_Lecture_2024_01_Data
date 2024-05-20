#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n) {
	int temp;

	for (int i = 0; i < n - 1; ++i) {
		int least = i;
		for (int j = i + 1; j < n; ++j) {
			if (list[j] < list[least]) {
				least = j;
			}
		}

		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = list[i];
		int j;
		for (j = i - 1; j >= 0 && list[j] > key; --j) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n) {
	int temp;
	for (int i = n - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
		}
	}
}

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > mid) {
		for (int l = j; l <= right; ++l) {
			sorted[k++] = list[l];
		}
	}
	else {
		for (int l = i; l <= mid; ++l) {
			sorted[k++] = list[l];
		}
	}

	for (int l = left; l <= right; ++l) {
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int partition(int list[], int left, int right) {
	int low = left, high = right + 1, pivot = list[left];
	int temp;

	do {
		do {
			low++;
		} while (low <= right && list[low] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high) {
			SWAP(list[low], list[high], temp);
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main() {
	int i;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < MAX_SIZE; i++) // 난수 생성 및 출력
		list[i] = rand() % 100; // 난수 발생 범위 0~MAX_SIZE
	//selection_sort(list, MAX_SIZE); // 선택 정렬 호출
	//insertion_sort(list, MAX_SIZE);
	//bubble_sort(list, MAX_SIZE);
	merge_sort(list, 0, MAX_SIZE - 1);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
