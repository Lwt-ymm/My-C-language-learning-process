#pragma once
#pragma warning(disable: 6031)

#include<stdio.h>//标准输入输出，printf、scanf
#include<time.h>//获取随机数
#include<Windows.h>//控制DOS界面，获取坐标位置、设置字体颜色
#include<conio.h>//接收键盘输入输出，kbhit、getch

//定义游戏框架所需常量
#define Frame_X 13 //游戏窗口左上角的横坐标
#define Frame_Y 3  //游戏窗口左上角的纵坐标
#define Frame_H 20 //游戏窗口高度
#define Frame_W 18 //游戏窗口宽度

//声明俄罗斯方块结构体
typedef struct Tetris
{
	int x;//记录俄罗斯方块“中心”小方块的位置
	int y;//记录俄罗斯方块“中心”小方块的位置
	int type;//俄罗斯方块的类型
	int next_type;//下一个俄罗斯方块类型
	int speed;//下路速度
	int number;
	int score;//当前分数
	int level;//当前分数对应的等级
}Tetris;

void title();//头标
void color(int c);//设置文本颜色
void gotoxy(int x, int y);//定位光标位置
void menu();//打印菜单
void build_gameframe();//建造游戏框架
void build_tetris(Tetris* tetris);//建造各种俄罗斯方块
void game();//选择1进入游戏界面
void print_tetris(Tetris* tetris);//打印各种俄罗斯方块
void ifmove(Tetris* tetris);//判断是否可以移动
