#include <stdio.h>
int main() {
	char op;
	int a, b;
	
	printf("������ �Է��ϼ���.\n");
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+')
		printf("\n%d", a + b);

	else if (op == '-')
		printf("\n%d", a - b);

	else if (op == '*')
		printf("\n%d", a * b);

	else if (op == '/')
		printf("\n%d", a / b);

	else printf("\n�߸��Է��ϼ̽��ϴ�.");

	return 0;
}