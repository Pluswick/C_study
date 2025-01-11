#include <stdio.h>
#include "maze.h"

int main() {
    char maze[ROWS][COLS];
    Player player = { 4, 0 }; // ���� ��ġ (S)

    initializeMaze(maze);

    printf("Welcome to the Text-Based Maze Game!\n");
    printf("Use 'w' (up), 's' (down), 'a' (left), 'd' (right) to move.\n");
    printf("Reach 'E' to exit the maze. Good luck!\n");

    while (1) {
        displayMaze(maze, player);

        // ����� �Է�
        char move;
        printf("\nEnter your move: ");
        scanf(" %c", &move);

        // �÷��̾� �̵�
        movePlayer(maze, &player, move);

        // �ⱸ ���� Ȯ��
        if (isExitReached(player)) {
            printf("\nCongratulations! You reached the exit!\n");
            break;
        }
    }

    return 0;
}
