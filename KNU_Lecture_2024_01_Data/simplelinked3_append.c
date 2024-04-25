#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* _remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

void append(ListNode* left, ListNode* right) {
	if (left == NULL) {
		return right;
	} else if (right == NULL) {
		return NULL;
	}
	else {
		ListNode* current = left;
		while (current->link != NULL) {
			current = current->link;
		}

		current->link = right;
	}

	
}

int main() {
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
	}
	print_list(head);


	ListNode* head2 = NULL;
	for (int i = 5; i < 10; ++i) {
		head2 = insert_first(head2, i);
	}
	print_list(head2);


	append(head, head2);
	print_list(head);
	return 0;
}