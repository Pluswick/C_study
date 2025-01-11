#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int* count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student* newStudent = &students[*count];

    printf("Enter student name: ");
    scanf("%s", newStudent->name);

    printf("Enter grades for 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &newStudent->grades[i]);
    }

    calculateStatistics(newStudent);

    (*count)++;
    printf("Student added successfully!\n");
}

void calculateStatistics(Student* student) {
    int sum = 0;
    student->highest = student->grades[0];
    student->lowest = student->grades[0];

    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
        if (student->grades[i] > student->highest) {
            student->highest = student->grades[i];
        }
        if (student->grades[i] < student->lowest) {
            student->lowest = student->grades[i];
        }
    }

    student->average = sum / 5.0;
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "Average", "Highest", "Lowest");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10d %-10d\n", students[i].name, students[i].average, students[i].highest, students[i].lowest);
    }
}

void saveToFile(Student students[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", students[i].name);
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%d ", students[i].grades[j]);
        }
        fprintf(file, "\n%.2f %d %d\n", students[i].average, students[i].highest, students[i].lowest);
    }

    fclose(file);
    printf("Data saved to file successfully!\n");
}

void loadFromFile(Student students[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d\n", count);
    for (int i = 0; i < *count; i++) {
        fscanf(file, "%s\n", students[i].name);
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%d", &students[i].grades[j]);
        }
        fscanf(file, "\n%f %d %d\n", &students[i].average, &students[i].highest, &students[i].lowest);
    }

    fclose(file);
    printf("Data loaded from file successfully!\n");
}
