#include<stdio.h>
int main()
{
	const float i = 7;
	float arr[7];
	for (int a = 0; a < i; a++)
	{
		scanf_s("%f", &arr[a]);
	}
	
	float sum = 0;
	for (int a = 0; a < i; a++)
		{
			sum += arr[a];
		}
	float length = sizeof(arr) / sizeof(float);

	printf("����� ��� ������ %.2f�� �Դϴ�.", sum /= length);

	return 0;
}