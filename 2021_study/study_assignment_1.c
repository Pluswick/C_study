#include <stdio.h>
int main() {
	/*�ڹμ� ���� ����*/
	int a, b;
	scanf_s("%d", &b);
	a = 1;
	int multi = 1;
	do 
	{
		multi = multi * a;
		a++;
	} 	while (a <= b);

	printf("1���� %d������ ��=%d\n", b, multi);

}