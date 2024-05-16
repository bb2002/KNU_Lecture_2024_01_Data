#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
	int height; // ����� ���� ���� �߰�
} TreeNode;

TreeNode* new_node(int key) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // �� ���� leaf ���� �߰���
	return(node);
}

int height(TreeNode* N) {
	if (N == NULL)
		return 0;
	return N->height;
}

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* search_iter(TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // Ž���� �������� ��� NULL ��ȯ
}

TreeNode* rightRotate(TreeNode* y) {
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;
	// ȸ�� ����
	x->right = y;
	y->left = T2;
	// ���� ������Ʈ
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	// ���ο� ��Ʈ ��ȯ
	return x;
}

TreeNode* leftRotate(TreeNode* x) {
	TreeNode* y = x->right;
	TreeNode* T2 = y->left;
	// ȸ�� ����
	y->left = x;
	x->right = T2;
	// ���� ������Ʈ
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// ���ο� ��Ʈ ��ȯ
	return y;
}

int getBalance(TreeNode* N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

TreeNode* rebalance(TreeNode* node, int key) {
	// ���� ���� Ȯ��
	int balance = getBalance(node);
	// ������ ������ ��� 4���� ���̽� ó��
   // LL Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	// RR Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	// LR Case
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// RL Case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node; // ���� ���� ��� ��ȯ
}

TreeNode* insert_node(TreeNode* node, int key) {
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);
	// �׷��� ������ ��������� Ʈ���� ��������. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
	// ���� ������Ʈ
	node->height = 1 + max(height(node->left), height(node->right));
	// ���� ���� Ȯ��
	int balance = getBalance(node);
	rebalance(node, key);
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	// �� ���� ���� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ��
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ��
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	// ���� ���� �� ����� ���� ������Ʈ
	root->height = 1 + max(height(root->left), height(root->right));
	rebalance(root, key);
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// ���� ����Ʈ�� ��ȸ
		printf("[%d] ", root->key); // ��� �湮
		inorder(root->right);// ������ ����Ʈ�� ��ȸ
	}
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	printf("AVR Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("AVR Ʈ������ 30�� �߰��� \n");
	else
		printf("AVR Ʈ������ 30�� �߰߸��� \n");
	return 0;
}