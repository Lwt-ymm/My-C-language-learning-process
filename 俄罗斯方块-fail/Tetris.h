#pragma once
#pragma warning(disable: 6031)

#include<stdio.h>//��׼���������printf��scanf
#include<time.h>//��ȡ�����
#include<Windows.h>//����DOS���棬��ȡ����λ�á�����������ɫ
#include<conio.h>//���ռ������������kbhit��getch

//������Ϸ������賣��
#define Frame_X 13 //��Ϸ�������Ͻǵĺ�����
#define Frame_Y 3  //��Ϸ�������Ͻǵ�������
#define Frame_H 20 //��Ϸ���ڸ߶�
#define Frame_W 18 //��Ϸ���ڿ��

//��������˹����ṹ��
typedef struct Tetris
{
	int x;//��¼����˹���顰���ġ�С�����λ��
	int y;//��¼����˹���顰���ġ�С�����λ��
	int type;//����˹���������
	int next_type;//��һ������˹��������
	int speed;//��·�ٶ�
	int number;
	int score;//��ǰ����
	int level;//��ǰ������Ӧ�ĵȼ�
}Tetris;

void title();//ͷ��
void color(int c);//�����ı���ɫ
void gotoxy(int x, int y);//��λ���λ��
void menu();//��ӡ�˵�
void build_gameframe();//������Ϸ���
void build_tetris(Tetris* tetris);//������ֶ���˹����
void game();//ѡ��1������Ϸ����
void print_tetris(Tetris* tetris);//��ӡ���ֶ���˹����
void ifmove(Tetris* tetris);//�ж��Ƿ�����ƶ�
