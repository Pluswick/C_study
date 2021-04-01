#include <stdio.h>
int main() {

	int year, leap;

	printf("Please enter the number of the year you want to figure out if that year and next year is leap year.\n");

	scanf_s("%d", &year);

	leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;


	printf("%d is %d\n", year, leap);
	year = year + 1;

	leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;

	printf("and one year later,\n%d is %d\n", year, leap);

	return 0;
}