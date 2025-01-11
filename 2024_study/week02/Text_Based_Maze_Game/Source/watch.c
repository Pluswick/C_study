#include <stdio.h>
#include <time.h>
#include "watch.h"

static time_t start_time;
static time_t end_time;

void start_timer() {
    printf("Press 's' to start the timer: ");
    char command;
    scanf(" %c", &command);

    if (command == 's') {
        start_time = time(NULL);
        printf("Timer started. Press 'e' to stop.\n");
    }
    else {
        printf("Invalid command. Timer not started.\n");
    }
}

void calculate_elapsed_time() {
    printf("Press 'e' to stop the timer: ");
    char command;
    scanf(" %c", &command);

    if (command == 'e') {
        end_time = time(NULL);
    }
    else {
        printf("Invalid command. Returning to main menu.\n");
        return;
    }
}

void display_time() {
    double elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
}
