#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int isBorrowed; // 0: Available, 1: Borrowed
} Book;

// 함수 선언
void addBook(Book books[], int* count);
void displayBooks(Book books[], int count);
void borrowBook(Book books[], int count);
void returnBook(Book books[], int count);
void saveToFile(Book books[], int count, const char* filename);
void loadFromFile(Book books[], int* count, const char* filename);

#endif
