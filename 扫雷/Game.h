#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROWS 11
#define COLS 11
#define ROW ROWS - 2 
#define COL COLS - 2
#define EASY 10

void Init_board(char board[ROWS][COLS], int rows, int cols, char set);
void Prin_board(char board[ROWS][COLS], int row, int col);
void PlaceMine(char board[ROWS][COLS], int row, int col);
void FoundMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col);