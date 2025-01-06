#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numBaseball.h"

void play_game() {
    int random_number[DIGITS], guess[DIGITS];
    int strike, ball;
    int attempts = 0;

    generate_random_number(random_number);

    printf("\nI have chosen a 3-digit number with all unique digits. Can you guess it?\n");

    while (1) {
        printf("Enter your guess (3 unique digits): ");
        for (int i = 0; i < DIGITS; i++) {
            scanf("%d", &guess[i]);
        }

        strike = 0;
        ball = 0;
        attempts++;

        evaluate_guess(random_number, guess, &strike, &ball);

        if (strike == DIGITS) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
        else {
            printf("%d Strike, %d Ball\n", strike, ball);
        }
    }
}

void generate_random_number(int* random_number) {
    srand(time(NULL));

    int used[10] = { 0 };
    for (int i = 0; i < DIGITS; i++) {
        int num;
        do {
            num = rand() % 10;
        } while (used[num]);

        random_number[i] = num;
        used[num] = 1;
    }
}

void evaluate_guess(int* random_number, int* guess, int* strike, int* ball) {
    *strike = 0;
    *ball = 0;

    for (int i = 0; i < DIGITS; i++) {
        if (guess[i] == random_number[i]) {
            (*strike)++;
        }
        else {
            for (int j = 0; j < DIGITS; j++) {
                if (guess[i] == random_number[j]) {
                    (*ball)++;
                    break;
                }
            }
        }
    }
}
