#ifndef MAZE_H
#define MAZE_H

#define ROWS 5
#define COLS 5

typedef struct {
    int x, y; // �÷��̾��� ���� ��ġ
} Player;

// �Լ� ����
void initializeMaze(char maze[ROWS][COLS]);
void displayMaze(char maze[ROWS][COLS], Player player);
void movePlayer(char maze[ROWS][COLS], Player* player, char direction);
int isExitReached(Player player);

#endif
