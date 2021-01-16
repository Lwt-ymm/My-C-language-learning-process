#include<stdio.h>//NULL
#include<time.h>//time
#include<stdlib.h>//rand srand

#define ROW 3
#define COL 3

void Game();
void Init_board(char board[ROW][COL],int row, int col);
void Print_board(char board[ROW][COL], int row, int col);
void Player_move(char board[ROW][COL], int row, int col);
void Computer_move(char board[ROW][COL], int row, int col);
char Game_state(char board[ROW][COL], int row, int col);