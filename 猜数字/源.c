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
	srand((unsigned)time(NULL));//���ò�������������
	secret = rand() % 10 + 1;//���������
	printf("�������λ���³�1-10֮�����������һ�����֣����²�����ĵ��Խ���һ�����ڹػ���\n");
	for (i = 0; i < 3; i++)//����3�β²����
	{
		scanf("%d", &guess);//������ҵĲ²�
		if (guess > secret)
			printf("�´��ˡ�\n");
		else if (guess < secret)
			printf("��С�ˡ�\n");
		else
		{
			printf("��ϲ�㣬�¶��ˡ�\n");
			printf("����һ���밴1���˳���Ϸ�밴0��\n");
			break;
		}
	}
	if (i == 3)//������ζ��´���
	{
		char input[20] = { 0 };
		printf("������λ��������꣬���Խ���һ�����ڹػ���\n");
		printf("����������롰��������ȡ���ػ���\n");
		system("shutdown -s -t 60");
	again:
		scanf("%s", &input);//ÿ��ѭ����Ҫ��ȡһ���û�����
		if (strcmp(input, "������") == 0)//������ȷ
		{
			system("shutdown -a");	
			printf("����һ���밴1���˳���Ϸ�밴0��\n");
		}
		else
		{
			printf("��ػ���໣����롰������ȡ����\n");
			goto again;//�����������һֱѭ��
		}
	}
}
int main()
{
	int a = 0;
	printf("**************************************\n");
	printf("***********   ��������Ϸ   ***********\n");
	printf("*****    1.play       0.exit     *****\n");
	printf("**************************************\n");
	do
	{
		scanf("%d", &a);//������ҵ�ѡ��
		switch (a)
		{
		case 1:
			printf("��ʼ��Ϸ��\n");
			Game();//��ת����Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("��ѡ��1��0\n");
			break;
		}
	} while (a);//0Ϊ�٣�����Ϊ��

	return 0;
}