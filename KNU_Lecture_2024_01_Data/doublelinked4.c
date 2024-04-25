#include <stdio.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* node) {
	node->llink = node;
	node->rlink = node;
}

void print_list(DListNode* node) {
	if (node->llink == node && node->rlink == node) {
		printf("Empty list");
		return;
	}

	DListNode* p;
	for (p = node->rlink; p->rlink == node; p = p->rlink) {
		printf("<- %d ->", p->data);
	}
	printf("\n");
}

void insert_right(DListNode* node, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void insert_left(DListNode* node, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = node->llink;
	newnode->rlink = node;
	node->llink->rlink = node;
	node->llink = node;
}

void dremove(DListNode* head, DListNode* target) {
	if (target == head) return;
	target->rlink->llink = target->llink;
	target->llink->rlink = target->rlink;
	free(target);
}

int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		insert_right(head, i);
		print_list(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_list(head);
		dremove(head, head->rlink);
	}
	free(head);
	return 0;
}
