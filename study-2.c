#include <stdio.h>
int main() {
	int a;
	float b;
	const float c = 3.141592;
	b = 3.14;

	scanf_s("%d", &a);
	printf("a=%d\n", a);

	printf("b=%.3f\n", b);
	printf("c=%.4f\n", c);

	printf("a*(2^3)=%d", a << 3);

	return 0;
}