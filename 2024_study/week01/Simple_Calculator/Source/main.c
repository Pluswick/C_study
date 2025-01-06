#include "functions.h"

int main() {
    int choice;
    double num1, num2;
    char history[MAX_HISTORY][50];
    int history_count = 0;

    while (1) {
        printf("\nSimple Calculator\n");
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division (Quotient and Remainder)\n");
        printf("5. View History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add(num1, num2, history, &history_count);
            break;
        case 2:
            subtract(num1, num2, history, &history_count);
            break;
        case 3:
            multiply(num1, num2, history, &history_count);
            break;
        case 4:
            if ((int)num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            }
            else {
                divide((int)num1, (int)num2, history, &history_count);
            }
            break;
        case 5:
            view_history(history, history_count);
            break;
        case 6:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}