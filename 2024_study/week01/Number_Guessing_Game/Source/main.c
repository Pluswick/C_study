#include <stdio.h>
#include "numBaseball.h"

int main() {
    int choice;

    while (1) {
        printf("\nNumber Baseball Game\n");
        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            play_game();
            break;
        case 2:
            printf("Exiting the game. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
