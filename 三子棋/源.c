#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

void Game()
{
	char result = 0;
	//创建棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Init_board(board, ROW, COL);
	//打印棋盘
	Print_board(board, ROW, COL);
	while (1)
	{
		//玩家走棋
		printf("玩家走棋：\n");
		Player_move(board, ROW, COL);
		Print_board(board, ROW, COL);
		//判断游戏状态 继续 平局 玩家胜 电脑胜
		result = Game_state(board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
		//电脑走棋
		printf("电脑走棋：\n");
		Computer_move(board, ROW, COL);
		Print_board(board, ROW, COL);
		//判断游戏状态 继续 平局 玩家胜 电脑胜
		result = Game_state(board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == 'X')
		printf("玩家胜\n");
	else if (result == 'O')
		printf("电脑胜\n");
	else
		printf("平局\n");
	printf("再来一局请输入1，退出请输入0\n");
}

void Menu()
{
	int input = 0;
	printf("*****************************\n");
	printf("****  1.play    2.exit   ****\n");
	printf("*****************************\n");
	do
	{
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入1或0\n");
			break;
		}
	} while (input);
}

int main()
{
	//设置随机数起点
	srand(time(NULL));
	//写一个游戏
	//打印菜单
	Menu();
	return 0;
}
