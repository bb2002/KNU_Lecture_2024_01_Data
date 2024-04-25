#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return q->front == q->rear;
}

int is_full(QueueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d) = ", q->front, q->rear);
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

void enqueue(QueueType* q, element data) {
	if (is_full(q)) {
		error("Queue is full");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = data;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty");
		return;
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main() {
	int min = 20;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);
	srand(time(NULL));

	for (int clock = 0; clock < min; clock++) {
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간: %d분\n", customer.id, customer.arrival_time, customer.service_time);

		}

		if (service_time > 0) {
			printf("고객 %d 업무 처리중 \n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d이 %d 분에 업무를 시작합니다.", customer.id, clock);
				printf("대기시간은 %d 분이었다.\n", clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}

	printf("전체대기시간 %d 분\n", total_wait);
	return 0;
}