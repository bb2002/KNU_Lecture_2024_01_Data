#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* next;
} GraphNode;

typedef struct GraphType {
	int n; // ������ ����
	GraphNode* adj_list[MAX_VERTICES];
	GraphNode* last_node[MAX_VERTICES]; // �� ���� ����Ʈ�� ���� ����Ű�� ������ �迭
} GraphType;

void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
		g->last_node[i] = NULL;
	}
}

void insert_vertex(GraphType* g) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����\n");
		return;
	}
	// ���� ������ ���� ���� ����Ʈ�� �߰�
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = end;
	node->next = NULL;
	if (g->adj_list[start] == NULL) {
		g->adj_list[start] = node;
		g->last_node[start] = node; // ���ο� ��尡 ������ ��尡 ��
	}
	else {
		g->last_node[start]->next = node; // ���� ������ ����� next�� �� ���� ����
		g->last_node[start] = node; // ���ο� ��尡 ������ ��尡 ��
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = start;
	node->next = NULL;
	if (g->adj_list[end] == NULL) {
		g->adj_list[end] = node;
		g->last_node[end] = node; // ���ο� ��尡 ������ ��尡 ��
	}
	else {
		g->last_node[end]->next = node; // ���� ������ ����� next�� �� ���� ����
		g->last_node[end] = node; // ���ο� ��尡 ������ ��尡 ��
	}
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ: ", i);
		while (node != NULL) {
			printf("%d -> ", node->vertex);
			node = node->next;
		}
		printf("NULL\n");
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];
		while (node != NULL) {
			GraphNode* temp = node;
			node = node->next;
			free(temp);
		}
	}
	free(g);
	return 0;
}