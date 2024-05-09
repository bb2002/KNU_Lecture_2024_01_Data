#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int evaluate(TreeNode* root) { // ���� ��� �Լ�
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d�� ����մϴ�.\n", op1, root->data, op2);
		switch (root->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
}

int main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { 16, NULL, NULL };
	TreeNode n5 = { 25, NULL, NULL };
	TreeNode n6 = { '+', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 };
	TreeNode* exp = &n7;
	printf("������ ���� %d�Դϴ�. \n", evaluate(exp));
	return 0;
}