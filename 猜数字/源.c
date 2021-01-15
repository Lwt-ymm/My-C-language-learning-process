#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//NULL
#include<stdlib.h>//rand  srand
#include<time.h>//time
#include<windows.h>//system
#include<string.h>//strcmp

void Game()
{
	int secret = 0;
	int guess = 0;
	int i = 0;
	srand((unsigned)time(NULL));//设置产生随机数的起点
	secret = rand() % 10 + 1;//产生随机数
	printf("你有三次机会猜出1-10之间随机产生的一个数字，若猜不出你的电脑将在一分钟内关机。\n");
	for (i = 0; i < 3; i++)//限制3次猜测次数
	{
		scanf("%d", &guess);//接收玩家的猜测
		if (guess > secret)
			printf("猜大了。\n");
		else if (guess < secret)
			printf("猜小了。\n");
		else
		{
			printf("恭喜你，猜对了。\n");
			printf("再来一局请按1，退出游戏请按0。\n");
			break;
		}
	}
	if (i == 3)//如果三次都猜错了
	{
		char input[20] = { 0 };
		printf("你的三次机会已用完，电脑将在一分钟内关机。\n");
		printf("但是如果输入“我是猪”则取消关机。\n");
		system("shutdown -s -t 60");
	again:
		scanf("%s", &input);//每次循环都要获取一次用户输入
		if (strcmp(input, "我是猪") == 0)//输入正确
		{
			system("shutdown -a");	
			printf("再来一局请按1，退出游戏请按0。\n");
		}
		else
		{
			printf("快关机了嗷，输入“我是猪”取消。\n");
			goto again;//若输入错误则一直循环
		}
	}
}
int main()
{
	int a = 0;
	printf("**************************************\n");
	printf("***********   猜数字游戏   ***********\n");
	printf("*****    1.play       0.exit     *****\n");
	printf("**************************************\n");
	do
	{
		scanf("%d", &a);//接收玩家的选择
		switch (a)
		{
		case 1:
			printf("开始游戏：\n");
			Game();//跳转到游戏程序
			break;
		case 0:
			printf("退出游戏。");
			break;
		default:
			printf("请选择1或0\n");
			break;
		}
	} while (a);//0为假，其余为真

	return 0;
}