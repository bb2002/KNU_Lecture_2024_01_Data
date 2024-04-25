#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) {
		printf("empty\n");
		return;
	}
	p = head->link;
	do
	{
		printf("%d ->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
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
	}
	return head;// 변경된 헤드 포인터를 반환한다. 
}

