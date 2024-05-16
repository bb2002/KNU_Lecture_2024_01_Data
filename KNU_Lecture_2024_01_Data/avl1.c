#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
	int height; // 노드의 높이 정보 추가
} TreeNode;

TreeNode* new_node(int key) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // 새 노드는 leaf 노드로 추가됨
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
	return NULL; // 탐색에 실패했을 경우 NULL 반환
}

TreeNode* rightRotate(TreeNode* y) {
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;
	// 회전 수행
	x->right = y;
	y->left = T2;
	// 높이 업데이트
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	// 새로운 루트 반환
	return x;
}

TreeNode* leftRotate(TreeNode* x) {
	TreeNode* y = x->right;
	TreeNode* T2 = y->left;
	// 회전 수행
	y->left = x;
	x->right = T2;
	// 높이 업데이트
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// 새로운 루트 반환
	return y;
}

int getBalance(TreeNode* N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

TreeNode* rebalance(TreeNode* node, int key) {
	// 균형 상태 확인
	int balance = getBalance(node);
	// 균형이 깨졌을 경우 4가지 케이스 처리
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
	return node; // 변경 없이 노드 반환
}

TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);
	// 그렇지 않으면 재귀적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	// 변경된 루트 포인터를 반환한다. 
	return node;
	// 높이 업데이트
	node->height = 1 + max(height(node->left), height(node->right));
	// 균형 상태 확인
	int balance = getBalance(node);
	rebalance(node, key);
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	// 맨 왼쪽 리프 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	// 삭제 연산 후 노드의 높이 업데이트
	root->height = 1 + max(height(root->left), height(root->right));
	rebalance(root, key);
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);// 왼쪽 서브트리 순회
		printf("[%d] ", root->key); // 노드 방문
		inorder(root->right);// 오른쪽 서브트리 순회
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
	printf("AVR 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("AVR 트리에서 30을 발견함 \n");
	else
		printf("AVR 트리에서 30을 발견못함 \n");
	return 0;
}