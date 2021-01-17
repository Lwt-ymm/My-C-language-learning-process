#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

int Sum(char board[ROWS][COLS], int x, int y)
{
	int tem = y;//����y��ֵ������ѭ���г�ʼ��yֵ
	//(x-1,y-1) (x-1,y)  (x-1,y+1)
	//(x,y-1)   (x,y)    (x,y+1)
	//(x+1,y-1) (x+1,y)  (x+1,y+1)
	int i = 0, j = 0;
	int sum = 0;
	for (i = 0; i < 3; i++, x++)
	{
		for (j = 0, y = tem; j < 3; j++, y++)
		{
			sum += board[x - 1][y - 1];
		}
	}
	sum = sum - 8 * (int)'0';
	return sum;
}
void Init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Prin_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	//��ӡ�к�
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
		if (i == 0)
			printf("  ");
	}
	printf("\n\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d   ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void PlaceMine(char board[ROWS][COLS], int row, int col)
{
	int count = 20;
	while (count)//���Ƶ��׸���
	{
		int x = 0, y = 0;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		board[x][y] = '1';
		count--;
	}
}
void FoundMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	//�ж����������Ƿ�Ϸ�
	while (1)
	{
		printf("���������׵����꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board1[x][y] == '1')
			{
				printf("��Ϸ�������������\n");
				break;
			}
			else
			{
				board2[x][y] = Sum(board1, x, y);
				Prin_board(board2, ROW, COL);
			}
		}
		else
			printf("����Ƿ�\n");
	}
	if (board1[x][y] != '1')
		printf("��ϲ�������Ϸ��\n");
}
