#include <stdio.h>
#include "library.h"

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    loadFromFile(books, &count, "library.txt");

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook(books, &count);
            break;
        case 2:
            displayBooks(books, count);
            break;
        case 3:
            borrowBook(books, count);
            break;
        case 4:
            returnBook(books, count);
            break;
        case 5:
            saveToFile(books, count, "library.txt");
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
