#include <stdio.h>
#include "watch.h"

int main() {
    int choice;

    while (1) {
        printf("\nStopwatch Menu:\n");
        printf("1. Start Timer\n");
        printf("2. Calculate Elapsed Time\n");
        printf("3. Display Elapsed Time\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            start_timer();
            break;
        case 2:
            calculate_elapsed_time();
            break;
        case 3:
            display_time();
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
