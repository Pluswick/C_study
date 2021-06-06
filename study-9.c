#include <stdio.h>


int fib(int i)
{
	if (i == 0)
		return 0;
	else if (i == 1)
		return 1;

	return fib(i - 1) + fib(i - 2);
}

int main()
{
	int n;

	scanf_s("%d", &n);

	printf("%d", fib(n));
}