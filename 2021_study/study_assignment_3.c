#include<stdio.h>

int multi8_bitshift(int x)
{
	int result = 0;
	result = x << 3;
	return result;
}

void cycle_do(int y, int z)
{
	int i = 1;
	int n;
	scanf_s("%d", &n);
	do
	{
		z = y << i;
		i++;
	} while (i <= n);

	printf("a * 2^n = %d\n", z);
	printf("½ÇÇà È½¼ö:%d\n", i);
}

int main()
{
	int a;
	scanf_s("%d", &a);
	printf("%d\n", multi8_bitshift(a));
	
	int b = 0;
	cycle_do(a, b);

	return 0;
}