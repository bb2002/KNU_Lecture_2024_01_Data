#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int Element;
typedef struct {
	Element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void err(const char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void init(ArrayListType* L) {
	L->size = 0;
}

int isEmpty(ArrayListType* L) {
	return L->size == 0;
}

int isFull(ArrayListType* l) {
	return l->size == MAX_LIST_SIZE;
}

Element getEntity(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size) {
		err("Out of Index Exception");
	}

	return L->array[pos];
}

void insertLast(ArrayListType* arr, Element e) {
	if (arr->size == MAX_LIST_SIZE) {
		err("ArrayList Overflow Exception");
	}

	arr->array[arr->size++] = e;
}

void insert(ArrayListType* arr, int pos, Element e) {
	if (!isFull(arr) && (pos >= 0) && (pos <= arr->size)) {
		for (int i = arr->size - 1; i >= pos; --i) {
			arr->array[i + 1] = arr->array[i];
		}

		arr->array[pos] = e;
		arr->size++;
	}
}

Element remove(ArrayListType* arr, int pos) {
	Element item;

	if (pos < 0 || pos >= arr->size) {
		err("OutOfIndex Exception");
	}

	item = arr->array[pos];
	for (int i = pos; i < (arr->size - 1); ++i) {
		arr->array[i] = arr->array[i + 1];
	}

	arr->size--;
	return item;
}

void printList(ArrayListType* arr) {
	for (int i = 0; i < arr->size; ++i) {
		printf("%d -> ", arr->array[i]);
	}
	printf("\n");
}

int main() {
	// ArrayListType를 정적으로 생성하고 ArrayListType를 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;
	init(&list);
	insert(&list, 0, 10);
	printList(&list);// 0번째 위치에 10 추가
	insert(&list, 0, 20);
	printList(&list);// 0번째 위치에 20 추가
	insert(&list, 0, 30);
	printList(&list);// 0번째 위치에 30 추가
	insertLast(&list, 40);
	printList(&list);// 맨 끝에 40 추가
	remove(&list, 0);
	printList(&list);// 0번째 항목 삭제
	printf("sizeof %d", sizeof(ArrayListType));
	return 0;
}
