#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;void print_list(ListNode* head) {	if (head == NULL) {		return;	}	ListNode* p = head->link;	do {		printf("ÇöÀç Â÷·Ê=%s\n", p->data);		p = p->link;	} while (p != head->link);}ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);
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

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}int main() {
	ListNode* head = NULL;
	head = insert_first(head, (char*)"PARK");
	head = insert_first(head, (char*)"CHOI");
	head = insert_first(head, (char*)"KIM");
	ListNode* p = head;
	for (int i = 0; i < 10; i++) {
		printf("ÇöÀç Â÷·Ê=%s \n", p->data);
		p = p->link;
		getchar();
	}
	return 0;
}