#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void printList(ListNode* head) {
	ListNode* p;
	if (head == NULL) {
		printf("empty\n");
		return;
	}
	p = head->link;

	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}

ListNode* insertFirst(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head;
}

ListNode* insertLast(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;// 변경된 헤드 포인터를 반환한다. 
}

ListNode* removeFirst(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* removed;
	if (head == head->link) {
		removed = head;
		head = NULL;
	}
	else {
		removed = head->link;
		head->link = removed->link;
	}

	free(removed);
	return head;
}

ListNode* removeLast(ListNode* head) {
	if (head == NULL) return NULL;

	if (head->link == head) {
		free(head);
		return NULL;
	}

	ListNode* current = head->link;
	while (current->link != head) {
		current = current->link;
	}

	current->link = head->link;
	free(head);
	head = current;

	return head;
}

int main() {
	ListNode* head = NULL;
	element data; // 삭제된 데이터를 저장할 변수
	// list = 10->20->30->40
	head = insertLast(head, 20);
	head = insertLast(head, 30);
	head = insertLast(head, 40);
	head = insertFirst(head, 10);
	printList(head);
	// 모든 요소를 제거
	head = removeLast(head);
	printList(head);
	head = removeFirst(head);
	printList(head);
	head = removeLast(head);
	printList(head);
	head = removeFirst(head);
	printList(head);
	return 0;
}
