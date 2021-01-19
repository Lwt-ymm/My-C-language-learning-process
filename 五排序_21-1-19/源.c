#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//�۰뷨����
void Half_order(int left, int right, int a[])
{
	int i = left, j = right;
	int middle = 0, temp = 0;
	middle = a[(left + right) / 2];//�������м�ֵ
	do
	{
		while (a[i] < middle && i < right)//�������С���м�ֵ����
			i++;
		while (a[j] > middle && j > left)//���ұ��Ҵ����м�ֵ����
			j--;
		if (i <= j)//����ҵ������������ֵ
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);//������ߵ��±꽻����ֹͣ
	if (left < j)//�ݹ�����
		Half_order(left, j, a);
	if (right > i)//�ݹ��Ұ��
		Half_order(i, right, a);
}
int main()
{
	int i = 0;
	int a[] = { 2,5,3,1,4 };
	int len = sizeof(a) / sizeof(a[0]);
	Half_order(0,len-1,a);
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

////���뷨����
//int main()
//{
//	int a[100] = { 2,5,3,1,4 };
//	int len = 5;
//	int temp = 0;
//	int pos = 0;
//	int i = 0;
//	printf("������Ҫ��������ĳ��ȣ��������Ԫ�أ�\n");
//	scanf("%d", &len);
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]=", i);
//		scanf("%d", &a[i]);
//	}
//	for (i = 1; i < len; i++)
//	{
//		temp = a[i];//Ҫ�����ֵ
//		pos = i - 1;
//		while (pos >= 0 && temp < a[pos])
//		{
//			a[pos + 1] = a[pos];
//			pos--;
//		}
//		a[pos + 1] = temp;
//	}
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

////����������
//int main()
//{
//	int a[100] = { 0 };
//	int len = 0;
//	int temp = 0;
//	int i = 0, j = 0;
//	printf("������Ҫ��������ĳ��ȣ��������Ԫ�أ�\n");
//	scanf("%d", &len);
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]=", i);
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i < len; i++)
//	{
//		temp = a[i];
//		for (j = i + 1; j < len; j++)
//		{
//			if (a[i] < a[j])
//			{
//				temp = a[j];
//				a[j] = a[i];
//				a[i] = temp;
//			}
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}

////ð�ݷ�����
//int main()
//{
//	int a[100] = { 5,2,4,3,1 };
//	int len = 0;
//	int temp = 0;
//	int i = 0, j = 0;
//	printf("������Ҫ��������ĳ��ȣ��������Ԫ�أ�\n");
//	scanf("%d", &len);
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]= ", i);
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i < len; i++)
//	{
//		for (j = len - 1; j > i; j--)
//		{
//			if (a[j] < a[j - 1])
//			{
//				temp = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

////ѡ������
//int main()
//{
//	int a[100] = { 1,2,3,4,5 };
//	int len = 0;
//	int temp = 0;//�ݴ����ֵ
//	int pos = 0;//�ݴ����ֵλ��
//	int i = 0, j = 0;
//	printf("����������ĳ��ȣ������������Ԫ�أ�\n");
//	scanf("%d", &len);//��ȡ���鳤��
//	//����Ҫ���������
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]= ", i);
//		scanf("%d", &a[i]);
//	}
//	//�����㷨ʵ��
//	for (i = 0; i < len - 1; i++)
//	{
//		temp = a[i];
//		pos = i;
//		for (j = i + 1; j < len; j++)
//		{
//			if (temp < a[j])
//			{
//				temp = a[j];
//				pos = j;
//			}
//			if (j == (len - 1))
//			{
//				a[pos] = a[i];
//				a[i] = temp;
//			}
//		}		
//	}
//	//��ӡ������ɵ�����
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}