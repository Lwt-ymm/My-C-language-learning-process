#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//折半法排序
void Half_order(int left, int right, int a[])
{
	int i = left, j = right;
	int middle = 0, temp = 0;
	middle = a[(left + right) / 2];//求数组中间值
	do
	{
		while (a[i] < middle && i < right)//从左边找小于中间值的数
			i++;
		while (a[j] > middle && j > left)//从右边找大于中间值的数
			j--;
		if (i <= j)//如果找到，交换这对数值
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);//如果两边的下标交错，就停止
	if (left < j)//递归左半边
		Half_order(left, j, a);
	if (right > i)//递归右半边
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

////插入法排序
//int main()
//{
//	int a[100] = { 2,5,3,1,4 };
//	int len = 5;
//	int temp = 0;
//	int pos = 0;
//	int i = 0;
//	printf("请输入要输入数组的长度，并输入各元素：\n");
//	scanf("%d", &len);
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]=", i);
//		scanf("%d", &a[i]);
//	}
//	for (i = 1; i < len; i++)
//	{
//		temp = a[i];//要插入的值
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

////交换法排序
//int main()
//{
//	int a[100] = { 0 };
//	int len = 0;
//	int temp = 0;
//	int i = 0, j = 0;
//	printf("请输入要输入数组的长度，并输入各元素：\n");
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

////冒泡法排序
//int main()
//{
//	int a[100] = { 5,2,4,3,1 };
//	int len = 0;
//	int temp = 0;
//	int i = 0, j = 0;
//	printf("请输入要输入数组的长度，并输入各元素：\n");
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

////选择法排序
//int main()
//{
//	int a[100] = { 1,2,3,4,5 };
//	int len = 0;
//	int temp = 0;//暂存最大值
//	int pos = 0;//暂存最大值位置
//	int i = 0, j = 0;
//	printf("请输入数组的长度，并依次输入各元素：\n");
//	scanf("%d", &len);//获取数组长度
//	//输入要排序的数组
//	for (i = 0; i < len; i++)
//	{
//		printf("a[%d]= ", i);
//		scanf("%d", &a[i]);
//	}
//	//排序算法实现
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
//	//打印排序完成的数组
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}