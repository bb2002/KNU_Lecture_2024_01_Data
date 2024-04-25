#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}int is_full(QueueType* q) {	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;}void enqueue(QueueType* q, element data) {	if (is_full(q)) {		error("Queue is full");		return;	}	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;	q->data[q->rear] = data;}element dequeue(QueueType* q) {	if (is_empty(q)) {		error("Queue is empty");		return;	}	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	return q->data[q->front];}void queue_print(QueueType* q) {	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);	if (!is_empty(q)) {		int i = q->front;		do {			i = (i + 1) % MAX_QUEUE_SIZE;			printf("%d | ", q->data[i]);			if (i == q->rear) {				break;			}		} while (i != q->front);	}	printf("\n");}int main() {
	QueueType queue;
	int element;
	init_queue(&queue);
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	return 0;
}