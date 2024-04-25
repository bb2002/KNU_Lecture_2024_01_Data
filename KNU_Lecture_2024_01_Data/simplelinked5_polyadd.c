#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // ��� Ÿ��
	double coef;
	int expon;
	struct ListNode* link;
} ListNode;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, double coef, int expon) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->coef = coef;
	p->expon = expon;
	p->link = head;
	head = p;
	return head;
}

ListNode* reverse(ListNode* head) {
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode* p, * q, * r;
	p = head; // p�� �������� ���� ����Ʈ
	q = NULL; // q�� �������� ���� ���
	while (p != NULL) {
		r = q; // r�� �������� �� ����Ʈ. 
		// r�� q, q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r; // q�� ��ũ ������ �ٲ۴�.
	}
	return q;
}

ListNode* poly_add(ListNode* list1, ListNode* list2, ListNode* list3) {
	ListNode* a = list1;
	ListNode* b = list2;
	ListNode* c = NULL;
	int sum;
	while (a && b) {
		if (a->expon == b->expon) { // a�� ���� > b�� ����
			sum = a->coef + b->coef;
			if (sum != 0)
				c = insert_first(c, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon) { // a�� ���� == b�� ����
			c = insert_first(c, a->coef, a->expon);
			a = a->link;
		}
		else {// a�� ���� < b�� ����
			c = insert_first(c, b->coef, b->expon);
			b = b->link;
		}
	}

	// a�� b���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ���
	// ��� ���׽����� ����
	for (; a != NULL; a = a->link)
		c = insert_first(c, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		c = insert_first(c, b->coef, b->expon);
	//�������� ���� ����
	return reverse(c);
}

void poly_print(ListNode* head) {
	ListNode* p = head->link;
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%.1fx^%d + ", p->coef, p->expon);
	printf("NULL \n"); \
}

int main() {
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;
	ListNode* list3 = NULL;
	// ���׽� 1�� ����
	list1 = insert_first(list1, 1, 0);
	list1 = insert_first(list1, 2, 8);
	list1 = insert_first(list1, 3, 12);
	// ���׽� 2�� ����
	list2 = insert_first(list2, 10, 6);
	list2 = insert_first(list2, -3, 10);
	list2 = insert_first(list2, 8, 12);
	poly_print(list1);
	poly_print(list2);
	printf("--------------------------------------------------------------------------\n");
	// ���׽� 3 = ���׽� 1 + ���׽� 2
	list3 = poly_add(list1, list2, list3);
	poly_print(list3);
	free(list1);
	free(list2);
	free(list3);
	return 0;
}
