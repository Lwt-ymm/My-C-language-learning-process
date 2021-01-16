#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

void Init_board(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int	j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Print_board(char board[ROW][COL], int row, int col)
{
	//   |   |
	//---|---|---
	//   |   |  
	//---|---|---
	//   |   |
	int i = 0;
	int	j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(j == col - 1)
				printf(" %c \n", board[i][j]);
			else
				printf(" %c |", board[i][j]);
		}
		if (i < row -1)
			printf("---|---|---\n");
	}
}
void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	//�ж��Ƿ�������� 1.�������� 2.��ռ�� 3.����Ƿ�
	while (1)
	{
		printf("������Ҫ���ӵ����꣺\n");
		scanf("%d%d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("������ռ�ã�����������\n");
		}
		else
			printf("����Ƿ�������������\n");

	}
}
void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while(1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
	printf("\n");
}
int Full_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char Game_state(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	//�ж����Ƿ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//�ж����Ƿ����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}//�ж϶Խ����Ƿ����
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[0][2];
	//�ж��Ƿ�ƽ��
	if (Full_board(board, ROW, COL) == 1)
		return 'D';
	//�������������������Ϸ����
	return 'C';
}