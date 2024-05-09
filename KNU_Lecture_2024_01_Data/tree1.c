#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	int left; // ���� �ڽ��� �ε���
	int right; // ������ �ڽ��� �ε���
} TreeNode;
#define MAX_NODES 10

int main() {
	TreeNode tree[MAX_NODES + 1];
	// Ʈ���� ���� �迭, 0�� �ε����� ��� X
	// �迭 �ʱ�ȭ
	for (int i = 1; i <= MAX_NODES; i++) {
		tree[i].data = 0;
		tree[i].left = -1;
		tree[i].right = -1;
	}
	// ��� ������ ����
	tree[1].data = 10; // ù ��° ��� (��Ʈ ���)
	tree[2].data = 20; // �� ��° ���
	tree[3].data = 30; // �� ��° ���

	// �ڽ� ��� �ε��� ����
	tree[1].left = 2; // ��Ʈ ����� ���� �ڽ�
	tree[1].right = 3; // ��Ʈ ����� ������ �ڽ�
	tree[2].left = -1; // �� ��° ���� �ڽ��� ����
	tree[2].right = -1;
	tree[3].left = -1; // �� ��° ���� �ڽ��� ����
	tree[3].right = -1;
	return 0;
}
