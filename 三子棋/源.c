#define _CRT_SECURE_NO_WARNINGS

#include"Game.h"

void Game()
{
	char result = 0;
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Init_board(board, ROW, COL);
	//��ӡ����
	Print_board(board, ROW, COL);
	while (1)
	{
		//�������
		printf("������壺\n");
		Player_move(board, ROW, COL);
		Print_board(board, ROW, COL);
		//�ж���Ϸ״̬ ���� ƽ�� ���ʤ ����ʤ
		result = Game_state(board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
		//��������
		printf("�������壺\n");
		Computer_move(board, ROW, COL);
		Print_board(board, ROW, COL);
		//�ж���Ϸ״̬ ���� ƽ�� ���ʤ ����ʤ
		result = Game_state(board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == 'X')
		printf("���ʤ\n");
	else if (result == 'O')
		printf("����ʤ\n");
	else
		printf("ƽ��\n");
	printf("����һ��������1���˳�������0\n");
}

void Menu()
{
	int input = 0;
	printf("*****************************\n");
	printf("****  1.play    2.exit   ****\n");
	printf("*****************************\n");
	do
	{
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������1��0\n");
			break;
		}
	} while (input);
}

int main()
{
	//������������
	srand(time(NULL));
	//дһ����Ϸ
	//��ӡ�˵�
	Menu();
	return 0;
}
