#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 문자열 길이 계산 함수
int calculateLength(char* str) {
	return strlen(str);
}

// 문자열 단어 개수 계산 함수
int countWords(char* str) {
	int count = 0;
	int inWord = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isspace(str[i]))
			inWord = 0;
		else if (inWord == 0) {
			inWord = 1;
			count++;
		}
	}
	return count;
}

// 문자열 뒤집기 함수
void reverseString(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main() {
	char input[256];
	int select;

	printf("문자열을 입력하세요: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';

	do {
		printf("***문자열 처리 도구***\n");
		printf("1. 문자열 길이 계산\n");
		printf("2. 단어 개수 계산\n");
		printf("3. 문자열 뒤집기\n");
		printf("4. 프로그램 종료\n");
		printf("\n선택: ");
		scanf("%d", &select);
		getchar();

		switch (select) {
		case 1:
			printf("문자열 길이: %d\n", calculateLength(input));
			break;
		case 2:
			printf("단어 개수: %d\n", countWords(input));
			break;
		case 3:
			reverseString(input);
			printf("문자열 뒤집기 결과: %s\n", input);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 옵션 선택입니다. 다시 선택하세요.\n");
		}
	} while (select != 4);

	return 0;
}