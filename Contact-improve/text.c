#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void Menu()
{
	printf("1.Add   \t2.Delete\n");
	printf("3.Search\t4.Modify\n");
	printf("5.Show  \t0.Exit\n");
	printf("---------------------------\n");
}

int main()
{
	//����ͨѶ¼
	struct Contact con;//con������ϵ����Ϣ��size��capacity
	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		Menu();
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case Add:
			AddContact(&con);
			break;
		case Delete:
			DeleteContact(&con);
			break;
		case Search:
			SearchContact(&con);
			break;
		case Modify:
			ModifyContact(&con);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Exit:
			SaveContact(&con);
			printf("����ɹ����˳�\n");
			break;
		default:
			printf("�������\n");
		}
	} while (input);
	return 0;
}