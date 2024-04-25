#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int Element;
typedef struct QueueNode {
	Element data;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
} LinkedQueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return q->front == NULL;
}

void queue_print(LinkedQueueType* q) {
	printf(" | ");
	for (QueueNode* p = q->front; p != NULL; p = p->next) {
		printf("%d | ", p->data);
	}
	printf("\n");
}

void enqueue(LinkedQueueType* q, Element data) {
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp == NULL) {
		error("Malloc error");
		return;
	}

	tmp->data = data;
	tmp->next = NULL;
	if (is_empty(q)) {
		q->front = tmp;
		q->rear = tmp;
	}
	else {
		q->rear->next = tmp;
		q->rear = tmp;
	}
}

Element dequeue(LinkedQueueType* q) {
	QueueNode* tmp = q->front;

	if (is_empty(q)) {
		error("Queue is empty");
		return;
	}

	Element data = tmp->data;
	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(tmp);
	return data;
}

int main() {
	LinkedQueueType q;
	init_queue(&q); // 큐 초기화
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	return 0;
}