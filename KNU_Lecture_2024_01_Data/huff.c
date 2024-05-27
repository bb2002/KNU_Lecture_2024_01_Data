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

TreeNode* huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x, * y;
	element e, e1, e2;
	HeapType* heap;
	heap = create();
	init(heap);
	// �󵵼��� ������� �ּ� ���� �ʱ�ȭ�Ѵ�.
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
	// �������� ���� 0�� ����
	if (root->left) {
		codes[top] = 0;
		print_codes(root->left, codes, top + 1);
	}
	// ���������� ���� 1�� ����
	if (root->right) {
		codes[top] = 1;
		print_codes(root->right, codes, top + 1);
	}
	// �ܸ� ��忡 �����ϸ� �ڵ带 ���
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
