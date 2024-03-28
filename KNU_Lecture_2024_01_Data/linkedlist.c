#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct ListNode {
	Element data;
	struct ListNode* next;
} ListNode;

ListNode* insertFirst(ListNode* head, Element val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->next = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* pre, Element val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->next = pre->next;
	pre->next = p;
	return pre;
}

ListNode* removeFirst(ListNode* head) {
	ListNode* removed;
	if (head == NULL) {
		return NULL;
	}

	removed = head;
	head = removed->next;
	free(removed);

	return head;
}

ListNode* del(ListNode* pre) {
	ListNode* removed;
	removed = pre->next;
	pre->next = removed->next;
	free(removed);
	return pre;
}

void printList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->next) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insertFirst(head, i);
		printList(head);
	}

	insert(head->next, 999);
	printList(head);
	del(head->next->next);
	printList(head);

	return 0;
}