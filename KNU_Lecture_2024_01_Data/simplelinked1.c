#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = (char*)malloc(sizeof(char) * 100);
	strcpy(p->data, value);
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = (char*)malloc(sizeof(char) * 100);
	strcpy(p->data, value);
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

//ListNode* remove(ListNode* head, ListNode* pre) {
//	ListNode* removed;
//	removed = pre->link;
//	pre->link = removed->link;
//	free(removed);
//	return head;
//}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	head = insert_first(head, "KIWI");
	head = insert_first(head, "BANANA");
	head = insert_first(head, "MANGO");

	print_list(head);
	
	return 0;
}