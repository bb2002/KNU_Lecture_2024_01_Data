#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// ���� �Լ�
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

void push_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

element pop_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;
	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		push_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = pop_max_heap(h);
	}
	free(h);
}


//int main() {
//	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
//	element e4, e5, e6;
//	HeapType* heap;
//	heap = create(); // �� ����
//	init(heap); // �ʱ�ȭ
//	// ����
//	push_max_heap(heap, e1);
//	push_max_heap(heap, e2);
//	push_max_heap(heap, e3);
//	// ����
//	e4 = pop_max_heap(heap);
//	printf("< %d > ", e4.key);
//	e5 = pop_max_heap(heap);
//	printf("< %d > ", e5.key);
//	e6 = pop_max_heap(heap);
//	printf("< %d > \n", e6.key);
//	free(heap);
//	return 0;
//
// }

int main() {
	element list[] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, 8);
	for (int i = 0; i < 8; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}
