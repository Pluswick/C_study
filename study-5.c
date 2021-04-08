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

	printf("당신의 평균 학점은 %.2f점 입니다.", sum /= length);

	return 0;
}