#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_counter_info 200
typedef struct customer_info {
    int use_time;
    int cost;
} customer_info;

typedef struct counter_info {
    int end_time;
    int counter_idx;
} counter_info;

typedef struct {
    counter_info heap[MAX_counter_info];
    int heap_size;
} HeapType;

// 생성 함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h) {
    h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 힙 h에 item을 삽입한다.
void push_min_heap(HeapType* h, counter_info item) {
    int i;
    i = ++(h->heap_size);
    // upheap
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.end_time < h->heap[i / 2].end_time
        || (item.end_time == h->heap[i / 2].end_time && item.counter_idx < h->heap[i / 2].counter_idx))) {
        // 비교 시 key가 같으면 counter_idx를 기준으로 정렬
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;    // 새로운 노드를 삽입
}

// 삭제 함수
counter_info pop_min_heap(HeapType* h) {
    int parent, child;
    counter_info item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];  parent = 1;
    child = 2;
    // downheap
    while (child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.  
        if ((child < h->heap_size) &&
            (h->heap[child].end_time > h->heap[child + 1].end_time
                || (h->heap[child].end_time == h->heap[child + 1].end_time && h->heap[child].counter_idx > h->heap[child + 1].counter_idx)))
            // 비교 시 key가 같으면 counter_idx를 기준으로 정렬
            child++;
        if (temp.end_time < h->heap[child].end_time ||
            (temp.end_time == h->heap[child].end_time && temp.counter_idx <= h->heap[child].counter_idx)) {
            // 비교 시 key가 같으면 counter_idx를 기준으로 정렬
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    int counter_idx_of_counter, counter_idx_of_customer;
    scanf("%d %d", &counter_idx_of_counter, &counter_idx_of_customer);

    counter_info* counter_list = (counter_info*)malloc((counter_idx_of_counter + 1) * sizeof(counter_info));
    for (int counter = 1; counter <= counter_idx_of_counter; counter++) {
        counter_list[counter].counter_idx = counter;
    }

    customer_info* customer_list = (customer_info*)malloc((counter_idx_of_customer + 1) * sizeof(customer_info));
    for (int customer = 1; customer <= counter_idx_of_customer; customer++) {
        scanf("%d %d", &customer_list[customer].use_time, &customer_list[customer].cost);
    }

    int total_time_answer = 0;

    int* counter_profit_answer = (int*)malloc((counter_idx_of_counter + 1) * sizeof(int));

    HeapType* pq = create();
    init(pq);

    for (int customer = 1; customer <= counter_idx_of_counter; customer++) {
        counter_list[customer].end_time = customer_list[customer].use_time;
        push_min_heap(pq, counter_list[customer]);

        counter_profit_answer[customer] = customer_list[customer].cost;
        total_time_answer = (total_time_answer > counter_list[customer].end_time) ? total_time_answer : counter_list[customer].end_time;
    }

    for (int customer = counter_idx_of_counter + 1; customer <= counter_idx_of_customer; customer++) {
        int counter = pop_min_heap(pq).counter_idx;
        counter_list[counter].end_time += customer_list[customer].use_time;
        push_min_heap(pq, counter_list[counter]);

        counter_profit_answer[counter] += customer_list[customer].cost;
        total_time_answer = (total_time_answer > counter_list[counter].end_time) ? total_time_answer : counter_list[counter].end_time;
    }

    printf("%d\n", total_time_answer);
    for (int counter = 1; counter <= counter_idx_of_counter; counter++) {
        printf("%d\n", counter_profit_answer[counter]);
    }

    return 0;
}
