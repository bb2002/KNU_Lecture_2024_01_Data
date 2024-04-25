#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int Element;
typedef struct { // 큐 타입
	Element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

int is_full(DequeType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) {
				break;
			}
		} while (i != q->front);
	}
}

void add_front(DequeType* q, Element val) {
	if (is_full(q)) {
		error("Deque is full");
		return;
	}

	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(DequeType* q, Element val) {
	if (is_full(q)) {
		error("Dequeue is full");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = val;
}

Element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("Deque is empty");
		return;
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

Element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q)) {
		error("Deque is empty");
		return;
	}

	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

Element get_front(DequeType* q) {
	if (is_empty(q)) {
		error("Deque is empty");
		return;
	}

	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

Element get_rear(DequeType* q) {
	if (is_empty(q)) {
		error("Deque is empty");
		return;
	}

	return q->data[q->rear];
}

int main() {
	DequeType queue;
	int element;
	init_deque(&queue);
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		add_front(&queue, element);
		deque_print(&queue);
	}
	while (!is_empty(&queue)) {
		element = delete_rear(&queue);
		printf("꺼내진 정수: %d \n", element);
		deque_print(&queue);
	}
	return 0;
}
