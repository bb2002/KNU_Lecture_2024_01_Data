#include<stdio.h>

double power(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return power(x * x, n / 2);
	}
	else {
		return x * power(x * x, (n - 1) / 2);
	}
}

int main() {
	printf("5^5 = %lf", power(5.0, 5));
}