#include"functions.h"

void add(double num1, double num2, char history[][50], int* history_count) {
    double result = num1 + num2;
    printf("Result: %.2lf\n", result);
    record_history("+", num1, num2, result, history, history_count);
}

void subtract(double num1, double num2, char history[][50], int* history_count) {
    double result = num1 - num2;
    printf("Result: %.2lf\n", result);
    record_history("-", num1, num2, result, history, history_count);
}

void multiply(double num1, double num2, char history[][50], int* history_count) {
    double result = num1 * num2;
    printf("Result: %.2lf\n", result);
    record_history("*", num1, num2, result, history, history_count);
}

void divide(int num1, int num2, char history[][50], int* history_count) {
    int quotient = num1 / num2;
    int remainder = num1 % num2;
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    record_division_history(num1, num2, quotient, remainder, history, history_count);
}


void view_history(char history[][50], int history_count) {
    if (history_count == 0) {
        printf("No history available.\n");
    }
    else {
        printf("\nCalculation History:\n");
        for (int i = 0; i < history_count; i++) {
            printf("%d. %s\n", i + 1, history[i]);
        }
    }
}

void record_history(char* operation, double num1, double num2, double result, char history[][50], int* history_count) {
    snprintf(history[*history_count], 50, "%.2lf %s %.2lf = %.2lf", num1, operation, num2, result);
    (*history_count)++;
}

void record_division_history(int num1, int num2, int quotient, int remainder, char history[][50], int* history_count) {
    snprintf(history[*history_count], 50, "%d / %d = Quotient: %d, Remainder: %d", num1, num2, quotient, remainder);
    (*history_count)++;
}
