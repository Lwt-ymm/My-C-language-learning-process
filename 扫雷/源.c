#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

void Game()
{
	//��������������һ����¼�ף�һ��չʾ�����
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ����������
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');
	//��ӡ����
	Prin_board(show, ROW, COL);
	//���õ���
	PlaceMine(mine, ROWS, COLS);
	//��ʼɨ��
	FoundMine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	//��ӡ�˵�
	int input = 0;
	printf("**********************************\n");
	printf("******* 1.play      0.exit *******\n");
	printf("**********************************\n");
	do
	{
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			Game();
			printf("����һ��������1���˳��밴0\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������1��0��\n");
			break;
		}
	} while (input);
	return 0;
}