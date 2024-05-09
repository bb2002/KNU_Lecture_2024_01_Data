#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	bool is_thread; // ���� ������ ��ũ�� �������̸� TRUE
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
	while (q->left) q = q->left; // ���� ���� ���� ����.
	do {
		printf("[%d] ", q->data); // ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q); // NULL�� �ƴϸ�
}


int main() {
	TreeNode n1 = { 1, NULL, NULL, true };
	TreeNode n2 = { 4, &n1, NULL, true };
	TreeNode n3 = { 16, NULL, NULL, true };
	TreeNode n4 = { 25, NULL, NULL, true };
	TreeNode n5 = { 20, &n3, &n4, false };
	TreeNode n6 = { 15, &n2, &n5, false };
	TreeNode* root = &n6;

	// ������ ����
	n1.right = &n2; // n1�� right�� n2�� ����Ű���� ����
	n2.right = &n6; // n2�� right�� n6�� ����Ű���� ����
	n3.right = &n5; // n3�� right�� n5�� ����Ű���� ����
	n4.right = NULL; // n4�� ���� ����̹Ƿ� NULL
	printf("���� ��ȸ= ");
	thread_inorder(root); // ���� ��ȸ ����
	printf("\n");
	return 0;
}