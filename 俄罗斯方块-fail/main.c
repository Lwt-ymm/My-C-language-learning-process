#define _CRT_SECURE_NO_WARNINGS

#include"Tetris.h"

//该数组在build_gameframe()中设置边界时记录边界坐标
int border[80][80] = { 0 };//0表示空，1表示方块，2表示边界
//该数组表示俄罗斯方块图形中的四个小方块的位置状态
int box[4] = { 1,1,1,1 };

int main()
{
	title();//俄罗斯方块头标
	menu();//打印菜单
	return 0;
}
