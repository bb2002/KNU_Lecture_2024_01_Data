#include<stdio.h>

#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;
} Poly;

Poly terms[MAX_TERMS] = { { 8,1 },{ 7,2 },{ 1,3 },{ 10,1 },{ 3,2 },{ 1,3 } };;
int avail = 6;

char compare(int a, int b) {
	if (a > b) {
		return '>';
	}
	else if (a == b) {
		return '=';
	}
	else {
		return '<';
	}
} 

void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "Too many Ç×");
		exit(1);
		return;
	}

	terms[avail].coef = coef;
	terms[avail].expon = expon;
	++avail;
}

void polyAdd2(int aStart, int aEnd, int bStart, int bEnd, int* cStart, int* cEnd) {
	float tempcoef;
	*cStart = avail;

	while (aStart <= aEnd && bStart <= bEnd) {
		switch (compare(terms[aStart].expon, terms[bStart].expon)) {
		case '>':
			attach(terms[aStart].coef, terms[aStart].expon);
			aStart++;
			break;
		case '=':
			tempcoef = terms[aStart].coef - terms[bStart].coef;
			if (tempcoef != 0) {
				attach(tempcoef, terms[aStart].expon);
			}
			aStart++;
			bStart++;
			break;
		case '<':
			attach(terms[bStart].coef, terms[bStart].expon);
			bStart++;
			break;
		}
	}

	for (; aStart <= aEnd; aStart++) {
		attach(terms[aStart].coef, terms[aStart].expon);
	}

	for (; bStart <= bEnd; bStart++) {
		attach(terms[bStart].coef, terms[bStart].expon);
	}
	*cEnd = avail - 1;
}

void printPoly(int start, int end) {
	for (int i = start; i < end; ++i) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}

	printf("%3.1fx^%d", terms[end].coef, terms[end].expon);
}

int main() {
	int aStart = 0, aEnd = 2, bStart = 3, bEnd = 5, cStart, cEnd;
	polyAdd2(aStart, aEnd, bStart, bEnd, &cStart, &cEnd);

	printf("(");
	printPoly(aStart, aEnd);
	printf(")");
	printf(" - ");

	printf("(");
	printPoly(bStart, bEnd);
	printf(")");
	printf("\n => ");
	printPoly(cStart, cEnd);
}