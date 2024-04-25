#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentTag {
	char name[10];
	int age;
	double gpa;
} Student;

int main() {
	Student* p;
	p = (Student*)malloc(sizeof(Student));
	if (p == NULL) {
		fprintf(stderr, "Out of Memory");
		return -1;
	}

	strcpy(p->name, "Ballbot");
	p->age = 20;
	printf("%s, %d", p->name, p->age);
	free(p);
	return 0;
}