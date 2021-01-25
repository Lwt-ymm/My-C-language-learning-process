#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>

int main()
{
	
	return 0;
}

////      *
////     ***
////    *****
////   *******
////  *********
//// ***********
////*************i *  row
//// *********** 0 11  7
////  *********  1 9   7
////   *******   2 7   7
////    *****
////     ***
////      *      5 1   7
//int main()
//{
//	int row = 0;
//	int i = 0;
//	scanf("%d", &row);//接收上半行数
//	//打印上半个
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < row - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < (2*i+1); j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半个
//	for (i = 0; i < row - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (row - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		int n = 1;
//		int sum = 0;
//		int temp = i;
//		//计算i的位数
//		while (temp /= 10)
//		{
//			n++;
//		}
//		//取得i的每位数的n次方之和
//		temp = i;
//		while (temp)
//		{
//			sum += pow(temp % 10, n);
//			temp /= 10;
//		}
//		if (i == sum)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0, n = 0;
//	int sum = 0;
//	int ret = 0;
//	scanf("%d%d", &a, &n);
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//char* reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str - 1 + len;
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//	return str;
//}
//
//int main()
//{
//	int arr[100] = { 0 };
//	//scanf("%s", &arr);//接收到空格就不再接收
//	gets(arr);//接收一行
//	printf("%s\n", reverse(arr));
//	return 0;
//}