#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	bool is_thread; // 만약 오른쪽 링크가 스레드이면 TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread)
		return q;
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) q = q->left; // 가장 왼쪽 노드로 간다.
	do {
		printf("[%d] ", q->data); // 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q); // NULL이 아니면
}


int main() {
	TreeNode n1 = { 1, NULL, NULL, true };
	TreeNode n2 = { 4, &n1, NULL, true };
	TreeNode n3 = { 16, NULL, NULL, true };
	TreeNode n4 = { 25, NULL, NULL, true };
	TreeNode n5 = { 20, &n3, &n4, false };
	TreeNode n6 = { 15, &n2, &n5, false };
	TreeNode* root = &n6;

	// 스레드 설정
	n1.right = &n2; // n1의 right가 n2를 가리키도록 설정
	n2.right = &n6; // n2의 right가 n6을 가리키도록 설정
	n3.right = &n5; // n3의 right가 n5를 가리키도록 설정
	n4.right = NULL; // n4는 리프 노드이므로 NULL
	printf("중위 순회= ");
	thread_inorder(root); // 중위 순회 실행
	printf("\n");
	return 0;
}