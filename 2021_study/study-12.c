#include <stdlib.h>
#include <stdio.h>

typedef struct student {
	char* name;
	int number;
	char major;
	struct student* link;
} STUDENT;

STUDENT* alloc_student(int size)
{
	struct STUDENT* s = malloc(sizeof(size));
}

void free_student(STUDENT* s)
{
	free(s);
}

void init_student(STUDENT* s, char* name, int number, char major)
{
	s->name = name;
	s->number = number;
	s->major = major;
}
void link_student(STUDENT* s1, STUDENT* s2)
{
	s1->link = &s2;
}

void print_student(STUDENT* s)
{
	printf("name=%s, number=%d, major=%d\n", s->name, s->number, s->major);
}

void print_all_student(STUDENT* s)
{
	print_student(s->link);
}

int main(void)
{
	STUDENT* s1, * s2, * s3;

	s1 = alloc_student(sizeof(STUDENT));
	s2 = alloc_student(sizeof(STUDENT));
	s3 = alloc_student(sizeof(STUDENT));

	init_student(s1, "Chulsoo Kim", 1000, 77);
	init_student(s2, "Younghee Lee", 2000, 77);
	init_student(s3, "Christina Park", 3000, 88);

	link_student(s3, NULL);
	link_student(s2, s3);
	link_student(s1, s2);

	print_all_student(s1);

	free_student(s1);
	free_student(s2);
	free_student(s3);

	return EXIT_SUCCESS;
}