typedef int element;
typedef struct {
	element* data; 
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("stack is empty");
		return;
	}

	return s->data[s->top--];
}

int main() {
	StackType* s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);

	push(s, 10);
	push(s, 20);
	pop(s);
	pop(s);
}