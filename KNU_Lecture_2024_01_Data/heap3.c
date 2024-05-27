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

// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

void push_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { // 여기
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

element pop_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };// 작업은 정렬되어 있다고 가정
	element m = { 0 };
	HeapType* h;
	h = create();
	init(h);
	for (int i = 0; i < MACHINES; i++) {
		m.machine = i + 1;
		m.key = 0;
		push_min_heap(h, m);
	}
	// 최소힙에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가 시킨 후에
	// 다시 최소힙에 추가한다. 
	for (int i = 0; i < JOBS; i++) {
		m = pop_min_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다. \n",
			i, m.key, m.key + jobs[i] - 1, m.machine);
		m.key += jobs[i];
		push_min_heap(h, m);
	}
	return 0;
}