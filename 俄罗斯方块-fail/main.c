#define _CRT_SECURE_NO_WARNINGS

#include"Tetris.h"

//��������build_gameframe()�����ñ߽�ʱ��¼�߽�����
int border[80][80] = { 0 };//0��ʾ�գ�1��ʾ���飬2��ʾ�߽�
//�������ʾ����˹����ͼ���е��ĸ�С�����λ��״̬
int box[4] = { 1,1,1,1 };

int main()
{
	title();//����˹����ͷ��
	menu();//��ӡ�˵�
	return 0;
}
