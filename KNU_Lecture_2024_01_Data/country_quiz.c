#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int benefit;
    int res_type;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
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
void push_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);
    // upheap
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.benefit > h->heap[i / 2].benefit
        || (item.benefit == h->heap[i / 2].benefit && item.res_type < h->heap[i / 2].res_type))) {
        // 비교 시 benefit이 같으면 res_type을 기준으로 정렬
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;    // 새로운 노드를 삽입
}

// 삭제 함수
element pop_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];  parent = 1;
    child = 2;
    // downheap
    while (child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.  
        if ((child < h->heap_size) &&
            (h->heap[child].benefit < h->heap[child + 1].benefit
                || (h->heap[child].benefit == h->heap[child + 1].benefit && h->heap[child].res_type > h->heap[child + 1].res_type)))
            // 비교 시 benefit이 같으면 res_type을 기준으로 정렬
            child++;
        if (temp.benefit > h->heap[child].benefit ||
            (temp.benefit == h->heap[child].benefit && temp.res_type <= h->heap[child].res_type)) {
            // 비교 시 benefit이 같으면 res_type을 기준으로 정렬
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
    int problem_num = 0;
    scanf("%d", &problem_num);

    for (int problem = 0; problem < problem_num; problem++) {
        int resource_num = 0;
        scanf("%d", &resource_num);

        HeapType* h = create();
        init(h);

        int* A_benefit = (int*)malloc(resource_num * sizeof(int));
        int* B_benefit = (int*)malloc(resource_num * sizeof(int));

        for (int res_type = 0; res_type < resource_num; res_type++) {
            int benefit1, benefit2;
            scanf("%d %d", &benefit1, &benefit2);
            A_benefit[res_type] = benefit1;
            B_benefit[res_type] = benefit2;
            push_max_heap(h, { (benefit1 + benefit2), res_type });
        }

        int A_benefit_sum = 0;
        int B_benefit_sum = 0;
        int is_A_turn = 1; // A의 차례인지 여부를 나타내는 변수. 1이면 A의 차례, 0이면 B의 차례.

        // 요소들을 번갈아가며 선택하며 이익을 계산
        for (int res_type = 0; res_type < resource_num; res_type++) {
            element item = pop_max_heap(h);
            if (is_A_turn) {
                A_benefit_sum += A_benefit[item.res_type];
            }
            else {
                B_benefit_sum += B_benefit[item.res_type];
            }
            is_A_turn = !is_A_turn;
        }

        printf("%d\n", A_benefit_sum - B_benefit_sum);
        free(h);
    }

    return 0;
}