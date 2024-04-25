#include<stdio.h>
#include<string.h>

typedef struct StudentTag {
	char name[10];
	int age;
	double score;
} Student;

int main() {
	struct StudentTag s;
	strcpy(s.name, "Ballbot");
	s.age = 20;
	s.score = 4.48;

	printf("Name: %s\n", s.name);
	printf("Age: %d\n", s.age);
	printf("Age: %lf\n", s.score);

	struct StudentTag s2 = { "Eggbot", 21, 3.37 };
	printf("Name: %s\n", s2.name);
	printf("Age: %d\n", s2.age);
	printf("Age: %lf\n", s2.score);

	Student s3 = { "GLaDOS", 9999, 4.5 };
	printf("Name: %s\n", s3.name);
	printf("Age: %d\n", s3.age);
	printf("Age: %lf\n", s3.score);
}