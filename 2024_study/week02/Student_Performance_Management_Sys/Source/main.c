#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // 메뉴 루프
    while (1) {
        printf("\nStudent Performance Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            saveToFile(students, count, "students.txt");
            break;
        case 4:
            loadFromFile(students, &count, "students.txt");
            break;
        case 5:
            printf("Exiting program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
