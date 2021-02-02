#define _CRT_SECURE_NO_WARNINGS

#include"Tetris.h"

//控制屏幕光标
void gotoxy(int x, int y)
{
	COORD pos = { 0 };
	pos.X = x;
	pos.Y = y;
	//将光标定位到（x，y）位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//设置文本颜色
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//头标打印
void title()
{
	color(15);//白色
	gotoxy(28, 2);
	printf("俄 罗 斯 方 块\n");

	color(11);//蓝色
	//█
	//██
	//█
	gotoxy(18, 5);
	printf("█");
	gotoxy(18, 6);
	printf("██");
	gotoxy(18, 7);
	printf("█");

	color(14);//黄色
	//██
	//  ██
	gotoxy(26, 6);
	printf("██");
	gotoxy(28, 7);
	printf("██");

	color(10);//绿色
	//██
	//██
	gotoxy(36, 6);
	printf("██");
	gotoxy(36, 7);
	printf("██");

	color(13);//粉色
	//█
	//█
	//█
	//█
	gotoxy(45, 4);
	printf("█");
	gotoxy(45, 5);
	printf("█");
	gotoxy(45, 6);
	printf("█");
	gotoxy(45, 7);
	printf("█");

	color(12);//红色
	//    █
	//███
	gotoxy(56, 6);
	printf("█");
	gotoxy(52, 7);
	printf("███");
}

//打印菜单
void menu()
{
	int n = 0;
	int i = 0;
	color(14);//黄色
	gotoxy(15, 9);
	for (i = 0; i <= 45; i++)
	{
		printf("=");
	}
	gotoxy(15, 20);
	for (i = 0; i <= 45; i++)
	{
		printf("=");
	}

	for (i = 0; i < 10; i++)
	{
		gotoxy(15, i + 10);
		printf("||");
	}
	for (i = 0; i < 10; i++)
	{
		gotoxy(59, i + 10);
		printf("||");
	}


	color(12);//红色
	gotoxy(25, 12);
	printf("1.开始游戏");
	gotoxy(40, 12);
	printf("2.按键说明");
	gotoxy(25, 17);
	printf("3.游戏规则");
	gotoxy(40, 17);
	printf("4.退出游戏");

	color(3);//蓝色
	gotoxy(30, 22);
	printf("请选择：");
	scanf("%d", &n);

	switch (n)
	{
	case 1:
		system("cls");//清屏并打印游戏框架
		build_gameframe();
		game();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

//建造游戏框架
void build_gameframe()
{
	int i = 0;
	extern border[80][80];
	gotoxy(Frame_X + Frame_W - 5, Frame_Y - 2);
	color(11);//湛蓝色
	printf("俄罗斯方块");
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 6);
	printf("下一个出现的方块是：");
	color(10);//绿色
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 8);
	printf("********************");
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 14);
	printf("********************");
	color(7);//银色
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 16);
	printf("Esc : 退出游戏");
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 18);
	printf("↑: 旋转");
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 20);
	printf("Space : 暂停游戏");

	color(14);//黄色
	gotoxy(Frame_X, Frame_Y);
	printf("┏━");
	gotoxy(Frame_X + 2 * Frame_W - 2, Frame_Y);
	printf("┓");
	gotoxy(Frame_X, Frame_Y + Frame_H);
	printf("┗━");
	gotoxy(Frame_X + 2 * Frame_W - 2, Frame_Y + Frame_H);
	printf("┛");
	for (i = 2; i < 2 * Frame_W - 2; i++)
	{
		gotoxy(Frame_X + i, Frame_Y);
		printf("━");
	}
	for (i = 2; i < 2 * Frame_W - 2; i++)
	{
		gotoxy(Frame_X + i, Frame_Y + Frame_H);
		printf("━");
		border[Frame_X + i][Frame_Y + Frame_H] = 2;
	}
	for (i = 1; i < Frame_H; i++)
	{
		gotoxy(Frame_X + 2 * Frame_W - 2, Frame_Y + i);
		printf("┃");
		border[Frame_X + 2 * Frame_W - 2][Frame_Y + i] = 2;
	}
	for (i = 1; i < Frame_H; i++)
	{
		gotoxy(Frame_X, Frame_Y + i);
		printf("┃");
		border[Frame_X][Frame_Y + i] = 2;
	}
}

//建造各种俄罗斯方块
void build_tetris(Tetris* tetris)
{
	extern box[4];
	extern border[80][80];
	border[tetris->x][tetris->y] = box[0];
	switch (tetris->type)
	{
	case 1:
		//██
		//██
		color(7);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x + 2][tetris->y - 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 2:
		//████
		color(8);
		border[tetris->x - 2][tetris->y] = box[1];
		border[tetris->x + 2][tetris->y] = box[2];
		border[tetris->x + 4][tetris->y] = box[3];
		break;
	case 3:
		//█
		//█
		//█
		//█
		color(8);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y - 2] = box[2];
		border[tetris->x][tetris->y + 1] = box[3];
		break;
	case 4:
		//███
		//  █
		color(9);
		border[tetris->x - 2][tetris->y] = box[1];
		border[tetris->x + 2][tetris->y] = box[2];
		border[tetris->x][tetris->y + 1] = box[3];
		break;
	case 5:
		//  █
		//██
		//  █
		color(9);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y + 1] = box[2];
		border[tetris->x - 2][tetris->y] = box[3];
		break;
	case 6:
		//  █
		//███
		color(9);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x - 2][tetris->y] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 7:
		//█
		//██
		//█
		color(9);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y + 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 8:
		//██
		//  ██
		color(10);
		border[tetris->x][tetris->y + 1] = box[1];
		border[tetris->x - 2][tetris->y] = box[2];
		border[tetris->x + 2][tetris->y + 1] = box[3];
		break;
	case 9:
		//  █
		//██
		//█
		color(10);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x - 2][tetris->y] = box[2];
		border[tetris->x - 2][tetris->y + 1] = box[3];
		break;
	case 10:
		//  ██
		//██
		color(10);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x - 2][tetris->y - 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 11:
		//█
		//██
		//  █
		color(10);
		border[tetris->x][tetris->y + 1] = box[1];
		border[tetris->x - 2][tetris->y - 1] = box[2];
		border[tetris->x - 2][tetris->y] = box[3];
		break;
	case 12:
		//██
		//  █
		//  █
		color(11);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y + 1] = box[2];
		border[tetris->x - 2][tetris->y - 1] = box[3];
		break;
	case 13:
		//    █
		//███
		color(11);
		border[tetris->x - 2][tetris->y] = box[1];
		border[tetris->x - 2][tetris->y - 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 14:
		//█
		//█
		//██
		color(11);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y + 1] = box[2];
		border[tetris->x + 2][tetris->y + 1] = box[3];
		break;
	case 15:
		//███
		//█
		color(11);
		border[tetris->x - 2][tetris->y - 1] = box[1];
		border[tetris->x - 2][tetris->y + 1] = box[2];
		border[tetris->x + 2][tetris->y + 1] = box[3];
		break;
	case 16:
		//██
		//█
		//█
		color(12);
		border[tetris->x][tetris->y + 1] = box[1];
		border[tetris->x][tetris->y - 1] = box[2];
		border[tetris->x + 2][tetris->y - 1] = box[3];
		break;
	case 17:
		//███
		//    █
		color(12);
		border[tetris->x - 2][tetris->y] = box[1];
		border[tetris->x + 2][tetris->y + 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	case 18:
		//  █
		//  █
		//██
		color(12);
		border[tetris->x][tetris->y - 1] = box[1];
		border[tetris->x][tetris->y + 1] = box[2];
		border[tetris->x - 2][tetris->y + 1] = box[3];
		break;
	case 19:
		//█
		//███
		color(12);
		border[tetris->x - 2][tetris->y] = box[1];
		border[tetris->x - 2][tetris->y - 1] = box[2];
		border[tetris->x + 2][tetris->y] = box[3];
		break;
	default :
		break;
	}
}

//选择1进入游戏界面
void game()
{
	//创建结构体指针,并初始化
	Tetris t = { 0 };
	Tetris* tetris = &t;
	tetris->number = 0;
	tetris->speed = 300;
	tetris->score = 0;
	tetris->level = 1;
	while (1)
	{
		int temp = 0;
		srand(time(NULL));//根据时间设置随机数起点
		//产生当前和下一个俄罗斯方块的类型，并记录
		tetris->type = rand() % 19 + 1;//产生1-19的随机数
		tetris->next_type = rand() % 19 + 1;
		temp = tetris->type;
		//获取打印“下一个方块”预览界面的坐标,并打印出下一个俄罗斯方块图形
		tetris->x = Frame_X + 2 * Frame_W + 10;
		tetris->y = Frame_Y + 11;
		tetris->type = tetris->next_type;
		print_tetris(tetris);

		tetris->x = Frame_X + Frame_W;
		tetris->y = Frame_Y - 1;
		tetris->next_type = temp;
		break;
	}
}

//打印各种俄罗斯方块
void print_tetris(Tetris* tetris)
{
	extern border[80][80];

	build_tetris(tetris);

	for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (int j = tetris->y - 2;j <= tetris->y + 1; j++)
		{
			if (border[i][j] == 1 && j > Frame_Y)
			{
				gotoxy(i, j);
				printf("█");
			}
		}
	}
	//打印分数等
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 0);
	color(4);
	printf("level : %d",tetris->level);
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 2);
	color(5);
	printf("score : %d", tetris->score);
	gotoxy(Frame_X + 2 * Frame_W + 3, Frame_Y + 4);
	color(6);
	printf("speed : %d ms", tetris->speed);
}

//判断是否可以移动
void ifmove(Tetris* tetris)
{
	extern border[80][80];
}