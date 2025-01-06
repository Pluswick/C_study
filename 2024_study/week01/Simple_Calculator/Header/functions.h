#ifndef FUNCTIONS_H

#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 100

void add(double num1, double num2, char history[][50], int* history_count);
void subtract(double num1, double num2, char history[][50], int* history_count);
void multiply(double num1, double num2, char history[][50], int* history_count);
void divide(int num1, int num2, char history[][50], int* history_count);
void view_history(char history[][50], int history_count);

void record_history(char* operation, double num1, double num2, double result, char history[][50], int* history_count);
void record_division_history(int num1, int num2, int quotient, int remainder, char history[][50], int* history_count);

#endif // !FUNCTIONS_H

