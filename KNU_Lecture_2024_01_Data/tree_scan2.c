#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100

int top = -1;
TreeNode* stack[SIZE]; //노드들을 쌓는 스택 선언

void push(TreeNode* p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop() {
	if (top >= 0)
		return stack[top--];
	return NULL;
}

void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

void preorder_iter(TreeNode* root) {
	while (1) {
		while (root) {
			printf("[%d] ", root->data);
			push(root);
			root = root->left;
		}
		root = pop();
		if (!root) break;
		root = root->right;
	}
}

void postorder_iter(TreeNode* root) {
	TreeNode* last_visited = NULL;
	while (1) {
		while (root) {
			push(root);
			root = root->left;
		}
		root = pop();
		while (root && (root->right == NULL || root->right == last_visited)) {
			printf("[%d] ", root->data);
			last_visited = root;
			root = NULL;
			if (top == -1) break;
			root = pop();
		}
		if (!root) break;
		push(root);
		root = root->right;
	}
}

int main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;
	printf("중위 순회= ");
	inorder_iter(root);
	printf("\n");
	printf("전위 순회= ");
	preorder_iter(root);
	printf("\n");
	printf("후위 순회= ");
	postorder_iter(root);
	printf("\n");
	return 0;
}