#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct TreeNode {
	int data; // weight
	char ch;
	struct TreeNode* left, * right;
} TreeNode;

typedef struct {
	int key;
	TreeNode* node;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void push_min_heap(HeapType* h, element item) {
	int i = 0;
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

TreeNode* huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x, * y;
	element e, e1, e2;
	HeapType* heap;
	heap = create();
	init(heap);
	// 빈도수를 기반으로 최소 힙을 초기화한다.
	for (i = 0; i < n; i++) {
		node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = freq[i];
		node->ch = ch_list[i];
		node->left = node->right = NULL;
		e.key = freq[i];
		e.node = node;
		push_min_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		e1 = pop_min_heap(heap);
		e2 = pop_min_heap(heap);
		node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = e1.key + e2.key;
		node->left = e1.node;
		node->right = e2.node;
		e.key = node->data;
		e.node = node;
		push_min_heap(heap, e);
		printf("%d+%d->%d\n", e1.key, e2.key, node->data);
	}
	printf("\n");
	e = pop_min_heap(heap);
	return e.node;
}

void print_codes(TreeNode* root, int codes[], int top) {
	// 왼쪽으로 가면 0을 저장
	if (root->left) {
		codes[top] = 0;
		print_codes(root->left, codes, top + 1);
	}
	// 오른쪽으로 가면 1을 저장
	if (root->right) {
		codes[top] = 1;
		print_codes(root->right, codes, top + 1);
	}
	// 단말 노드에 도착하면 코드를 출력
	if (!(root->left) && !(root->right)) {
		printf("%c: ", root->ch);
		for (int i = 0; i < top; i++) {
			printf("%d", codes[i]);
		}
		printf("\n");
	}
}

int main() {
	HeapType* h;
	h = create();
	init(h);
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4, 6, 8, 12, 15 };
	int codes[MAX_ELEMENT];
	TreeNode* root = huffman_tree(freq, ch_list, 5);
	print_codes(root, codes, 0);
	return 0;
}
