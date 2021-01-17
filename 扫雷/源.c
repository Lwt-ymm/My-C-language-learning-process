#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

void Game()
{
	//创建两个雷区，一个记录雷，一个展示给玩家
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化两个雷区
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');
	//打印雷区
	Prin_board(show, ROW, COL);
	//布置地雷
	PlaceMine(mine, ROWS, COLS);
	//开始扫雷
	FoundMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	//打印菜单
	int input = 0;
	printf("**********************************\n");
	printf("******* 1.play      0.exit *******\n");
	printf("**********************************\n");
	do
	{
		printf("请选择：\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			Game();
			printf("再来一局请输入1，退出请按0\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入1或0：\n");
			break;
		}
	} while (input);
	return 0;
}