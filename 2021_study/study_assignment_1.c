#include <stdio.h>
int main() {
	/*박민석 개인 과제*/
	int a, b;
	scanf_s("%d", &b);
	a = 1;
	int multi = 1;
	do 
	{
		multi = multi * a;
		a++;
	} 	while (a <= b);

	printf("1부터 %d까지의 곱=%d\n", b, multi);

}