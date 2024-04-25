#include<stdio.h>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} Polynomial;

Polynomial polySub(Polynomial a, Polynomial b) {
	Polynomial c;
	int aPos = 0, bPos = 0, cPos = 0;
	int degreeA = a.degree;
	int degreeB = b.degree;
	c.degree = MAX(a.degree, b.degree);

	while (aPos <= a.degree && bPos <= b.degree) {
		if (degreeA > degreeB) {
			c.coef[cPos++] = a.coef[aPos++];
			degreeA--;
		}
		else if (degreeA == degreeB) {
			c.coef[cPos++] = a.coef[aPos++] - b.coef[bPos++];
			degreeA--;
			degreeB--;
		}
		else {
			c.coef[cPos++] = b.coef[bPos++];
			degreeB--;
		}
	}

	return c;
}

void printPoly(Polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d", fabs((p.coef[p.degree - i])), i);
		if (p.coef[p.degree - i + 1] >= 0) {
			printf(" + ");
		} else {
			printf(" - ");
		}
	}
	printf("%3.1f \n", p.coef[p.degree]);
}

int main() {
	Polynomial a = { 5, { 3,5,8,4,4,7 } };
	Polynomial b = { 4, { 6,9,3,0,1 } };

	printPoly(a);
	printPoly(b);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printPoly(polySub(a, b));
	return 0;
}