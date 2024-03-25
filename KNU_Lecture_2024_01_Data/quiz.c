#include <stdio.h>
#include <stdlib.h>
int main()
{
	double* p1;
	p1 = (double*)malloc(sizeof(double));
	*p1 = 23.92;
	printf("%f", *p1);
	free(p1);

	for (int i = 0x0; i <= 0xfffffff; ++i) {
		free(i);
	}
	return 0;
}