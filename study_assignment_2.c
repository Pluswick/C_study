#include <stdio.h>

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &arr[i]);
	}

	int sum = 0;
	for (int k = 0; k < 5; k++) {
		sum += arr[k];
	}
	printf("%d\n", sum);

	return 0;
}