#include <stdio.h>
#include "maze.h"

int main() {
    char maze[ROWS][COLS];
    Player player = { 4, 0 }; // 시작 위치 (S)

    initializeMaze(maze);

    printf("Welcome to the Text-Based Maze Game!\n");
    printf("Use 'w' (up), 's' (down), 'a' (left), 'd' (right) to move.\n");
    printf("Reach 'E' to exit the maze. Good luck!\n");

    while (1) {
        displayMaze(maze, player);

        // 사용자 입력
        char move;
        printf("\nEnter your move: ");
        scanf(" %c", &move);

        // 플레이어 이동
        movePlayer(maze, &player, move);

        // 출구 도달 확인
        if (isExitReached(player)) {
            printf("\nCongratulations! You reached the exit!\n");
            break;
        }
    }

    return 0;
}
