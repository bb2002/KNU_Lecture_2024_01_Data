#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200
#define JOBS 8
#define MACHINES 3

typedef struct {
	int key;
	int machine;
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

void push_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { // ����
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

element pop_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };// �۾��� ���ĵǾ� �ִٰ� ����
	element m = { 0 };
	HeapType* h;
	h = create();
	init(h);
	for (int i = 0; i < MACHINES; i++) {
		m.machine = i + 1;
		m.key = 0;
		push_min_heap(h, m);
	}
	// �ּ������� ��踦 ������ �۾��� �Ҵ��ϰ� ��밡�� �ð��� ���� ��Ų �Ŀ�
	// �ٽ� �ּ����� �߰��Ѵ�. 
	for (int i = 0; i < JOBS; i++) {
		m = pop_min_heap(h);
		printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ��Ѵ�. \n",
			i, m.key, m.key + jobs[i] - 1, m.machine);
		m.key += jobs[i];
		push_min_heap(h, m);
	}
	return 0;
}