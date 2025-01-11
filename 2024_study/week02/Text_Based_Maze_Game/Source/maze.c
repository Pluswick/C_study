#include <stdio.h>
#include "maze.h"

// 미로 초기화
void initializeMaze(char maze[ROWS][COLS]) {
    // 0: 길, 1: 벽, E: 출구
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

// 미로 출력
void displayMaze(char maze[ROWS][COLS], Player player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == player.x && j == player.y) {
                printf("P "); // 플레이어 위치
            }
            else if (maze[i][j] == '1') {
                printf("# "); // 벽
            }
            else if (maze[i][j] == '0') {
                printf(". "); // 길
            }
            else {
                printf("%c ", maze[i][j]); // 출구(E) 또는 시작점(S)
            }
        }
        printf("\n");
    }
}

// 플레이어 이동 처리
void movePlayer(char maze[ROWS][COLS], Player* player, char direction) {
    int newX = player->x;
    int newY = player->y;

    // 방향에 따른 좌표 변경
    switch (direction) {
    case 'w': newX--; break; // 위
    case 's': newX++; break; // 아래
    case 'a': newY--; break; // 왼쪽
    case 'd': newY++; break; // 오른쪽
    default: printf("Invalid move!\n"); return;
    }

    // 경계 확인 및 이동 가능 여부 체크
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
        if (maze[newX][newY] != '1') { // 벽이 아닌 경우 이동
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

// 출구 도달 여부 확인
int isExitReached(Player player) {
    return (player.x == 0 && player.y == COLS - 1); // E 위치
}
