#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) {
		return NULL;
	}

	if (key == node->key) {
		return node;
	}
	else if (key < node->key) {
		return search(node->left, key);
	}
	else {
		return search(node->right, key);
	}
}

TreeNode* searchWithWhile(TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->key) {
			return node;
		}
		else if (key < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return NULL;
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;

}

TreeNode* insert(TreeNode* node, int key) {
	if (node == NULL) {
		return new_node(key);
	}

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* del(TreeNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (key < root->key) {
		root->left = del(root->left, key);
	}
	else if (key > root->key) {
		root->right = del(root->right, key);
	}
	else {
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

		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = del(root->right, temp->key);
	}

	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽 서브트리 순회
		printf("[%d] ", root->key); // 노드 방문
		inorder(root->right);// 오른쪽 서브트리 순회
	}
}


int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}