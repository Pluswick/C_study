#include <stdio.h>
#include <string.h>
#include "library.h"

// ���ο� å �߰�
void addBook(Book books[], int* count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", books[*count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", books[*count].author);
    books[*count].isBorrowed = 0; // �� å�� �⺻������ ���� ���� ����

    (*count)++;
    printf("Book added successfully!\n");
}

// å ��� ���
void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-30s %-20s %-10s\n", "Title", "Author", "Status");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-20s %-10s\n", books[i].title, books[i].author,
            books[i].isBorrowed ? "Borrowed" : "Available");
    }
}

// å ����
void borrowBook(Book books[], int count) {
    char title[TITLE_LEN];
    printf("Enter the title of the book to borrow: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            if (books[i].isBorrowed) {
                printf("This book is already borrowed.\n");
                return;
            }
            else {
                books[i].isBorrowed = 1;
                printf("You borrowed the book: %s\n", books[i].title);
                return;
            }
        }
    }
    printf("Book not found.\n");
}

// å �ݳ�
void returnBook(Book books[], int count) {
    char title[TITLE_LEN];
    printf("Enter the title of the book to return: ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            if (books[i].isBorrowed) {
                books[i].isBorrowed = 0;
                printf("You returned the book: %s\n", books[i].title);
                return;
            }
            else {
                printf("This book was not borrowed.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

// ���Ͽ� ������ ����
void saveToFile(Book books[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%d\n", books[i].title, books[i].author, books[i].isBorrowed);
    }

    fclose(file);
    printf("Library data saved to file successfully!\n");
}

// ���Ͽ��� ������ �ε�
void loadFromFile(Book books[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d\n", count);
    for (int i = 0; i < *count; i++) {
        fgets(books[i].title, TITLE_LEN, file);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // ���� ���� ����
        fgets(books[i].author, AUTHOR_LEN, file);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // ���� ���� ����
        fscanf(file, "%d\n", &books[i].isBorrowed);
    }

    fclose(file);
    printf("Library data loaded from file successfully!\n");
}
