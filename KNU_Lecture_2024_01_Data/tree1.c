#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	int left; // 왼쪽 자식의 인덱스
	int right; // 오른쪽 자식의 인덱스
} TreeNode;
#define MAX_NODES 10

int main() {
	TreeNode tree[MAX_NODES + 1];
	// 트리를 위한 배열, 0번 인덱스는 사용 X
	// 배열 초기화
	for (int i = 1; i <= MAX_NODES; i++) {
		tree[i].data = 0;
		tree[i].left = -1;
		tree[i].right = -1;
	}
	// 노드 데이터 설정
	tree[1].data = 10; // 첫 번째 노드 (루트 노드)
	tree[2].data = 20; // 두 번째 노드
	tree[3].data = 30; // 세 번째 노드

	// 자식 노드 인덱스 설정
	tree[1].left = 2; // 루트 노드의 왼쪽 자식
	tree[1].right = 3; // 루트 노드의 오른쪽 자식
	tree[2].left = -1; // 두 번째 노드는 자식이 없다
	tree[2].right = -1;
	tree[3].left = -1; // 세 번째 노드는 자식이 없다
	tree[3].right = -1;
	return 0;
}
