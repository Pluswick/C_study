#include <stdio.h>

int main()
{
	int input;
	scanf_s("%d", &input);

	int sumFor = 0;
	for (int i = 0; i <= input; i++)
	{
		sumFor += i;
	}

	int sumWhile = 0; 
	int i = 0; 
	while (input >= i)
	{
		sumWhile += i; 
		i++; 
	}

	printf("%d %d", sumFor, sumWhile);
}