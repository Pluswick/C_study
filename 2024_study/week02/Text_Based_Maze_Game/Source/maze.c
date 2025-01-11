#include <stdio.h>
#include "maze.h"

// �̷� �ʱ�ȭ
void initializeMaze(char maze[ROWS][COLS]) {
    // 0: ��, 1: ��, E: �ⱸ
    char template[ROWS][COLS] = {
        {'0', '0', '1', '1', 'E'},
        {'1', '0', '1', '1', '1'},
        {'1', '0', '0', '0', '1'},
        {'1', '1', '1', '0', '1'},
        {'S', '0', '0', '0', '1'},
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = template[i][j];
        }
    }
}

// �̷� ���
void displayMaze(char maze[ROWS][COLS], Player player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.x && j == player.y) {
                printf("P "); // �÷��̾� ��ġ
            }
            else if (maze[i][j] == '1') {
                printf("# "); // ��
            }
            else if (maze[i][j] == '0') {
                printf(". "); // ��
            }
            else {
                printf("%c ", maze[i][j]); // �ⱸ(E) �Ǵ� ������(S)
            }
        }
        printf("\n");
    }
}

// �÷��̾� �̵� ó��
void movePlayer(char maze[ROWS][COLS], Player* player, char direction) {
    int newX = player->x;
    int newY = player->y;

    // ���⿡ ���� ��ǥ ����
    switch (direction) {
    case 'w': newX--; break; // ��
    case 's': newX++; break; // �Ʒ�
    case 'a': newY--; break; // ����
    case 'd': newY++; break; // ������
    default: printf("Invalid move!\n"); return;
    }

    // ��� Ȯ�� �� �̵� ���� ���� üũ
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
        if (maze[newX][newY] != '1') { // ���� �ƴ� ��� �̵�
            player->x = newX;
            player->y = newY;
        }
        else {
            printf("You hit a wall!\n");
        }
    }
    else {
        printf("Out of bounds!\n");
    }
}

// �ⱸ ���� ���� Ȯ��
int isExitReached(Player player) {
    return (player.x == 0 && player.y == COLS - 1); // E ��ġ
}
