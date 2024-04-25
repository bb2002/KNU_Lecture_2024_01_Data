#include<stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} Polynomial;

Polynomial polyAdd(Polynomial a, Polynomial b) {
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
			c.coef[cPos++] = a.coef[aPos++] + b.coef[bPos++];
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
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}
/*
Polynomial polyAdd2(Polynomial a, Polynomial b) {
	printPoly(a);
	printPoly(b);

	Polynomial c;
	int aPos = 0, bPos = 0, cPos = 0;
	int degreeA = a.degree;
	int degreeB = b.degree;
	c.degree = MAX(a.degree, b.degree);

	while (aPos <= a.degree && bPos <= b.degree) {
		if (a.degree < b.degree) {
			c.coef[cPos++] = b.coef[bPos++];
			b.degree--;
		}
		else if (a.degree == b.degree) {
			c.coef[cPos++] = a.coef[aPos++] + b.coef[bPos++];
			a.degree--;
			b.degree--;
		}
		else {
			c.coef[cPos++] = a.coef[aPos++];
			a.degree--;
		}
	}

	return c;
}
*/

int main() {
	Polynomial a = { 5, { 3.0,6.0,0.0,0.0,0.0,10.0 } };
	Polynomial b = { 4, { 7.0,0.0,5.0,0.0,1.0 } };
	
	//printPoly(a);
	//printPoly(b);
	//printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	// printPoly(polyAdd2(a, b));
	return 0;
	//printPoly(polyAdd(a, b));
}