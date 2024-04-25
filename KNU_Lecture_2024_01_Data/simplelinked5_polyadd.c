#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
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
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;
	p = head; // p는 역순으로 만들 리스트
	q = NULL; // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트. 
		// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; // q의 링크 방향을 바꾼다.
	}
	return q;
}

ListNode* poly_add(ListNode* list1, ListNode* list2, ListNode* list3) {
	ListNode* a = list1;
	ListNode* b = list2;
	ListNode* c = NULL;
	int sum;
	while (a && b) {
		if (a->expon == b->expon) { // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0)
				c = insert_first(c, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon) { // a의 차수 == b의 차수
			c = insert_first(c, a->coef, a->expon);
			a = a->link;
		}
		else {// a의 차수 < b의 차수
			c = insert_first(c, b->coef, b->expon);
			b = b->link;
		}
	}

	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		c = insert_first(c, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		c = insert_first(c, b->coef, b->expon);
	//역순으로 만들어서 리턴
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
	// 다항식 1을 생성
	list1 = insert_first(list1, 1, 0);
	list1 = insert_first(list1, 2, 8);
	list1 = insert_first(list1, 3, 12);
	// 다항식 2를 생성
	list2 = insert_first(list2, 10, 6);
	list2 = insert_first(list2, -3, 10);
	list2 = insert_first(list2, 8, 12);
	poly_print(list1);
	poly_print(list2);
	printf("--------------------------------------------------------------------------\n");
	// 다항식 3 = 다항식 1 + 다항식 2
	list3 = poly_add(list1, list2, list3);
	poly_print(list3);
	free(list1);
	free(list2);
	free(list3);
	return 0;
}
