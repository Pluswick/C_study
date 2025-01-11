#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int grades[5];
    float average;
    int highest;
    int lowest;
} Student;

// 함수 선언
void addStudent(Student students[], int* count);
void calculateStatistics(Student* student);
void displayStudents(Student students[], int count);
void saveToFile(Student students[], int count, const char* filename);
void loadFromFile(Student students[], int* count, const char* filename);

#endif
