#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	int nums[] = { 1,1,2 };
	int numsSize = 0;
	int i = 0, j = 0, tep = 0;
	int len = sizeof(nums) / sizeof(nums[0]);//����ԭ���鳤��
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)//�жϵ�i����֮���Ƿ������i��Ԫ����ȵ���
		{
			if (nums[i] == ' ')//�����i��Ԫ���ѱ�����Ϊ�գ�������ѭ��
				break;
			if (nums[i] == nums[j])//����ҵ�һ�����i��Ԫ����ȵ���
			{
				tep = nums[i];//�ݴ��i��Ԫ��
				for (int m = 0; m < j; m++)//Ѱ�ұ��ҵ��ĵ�j��Ԫ��֮ǰ�ĵ�һ����Ԫ��
				{
					if (nums[m] == ' ')
					{
						nums[m] = nums[i];//�����ŵ�ǰ��ĵ�һ����Ԫ����
						nums[i] = ' ';//���õ�i��Ԫ��Ϊ��
						break;
					}
				}
				numsSize++;
				for (j = i + 1; j < len - 1; j++)//Ѱ�Ҳ����õ�i��������������ȵ�Ԫ��
				{
					if (tep == nums[j])
						nums[j] = ' ';
				}
				break;
			}
			else if (j == 9)//���û���ҵ����i��Ԫ����ȵ���
			{
				for (int m = 0; m < j; m++)//Ѱ�Ҹ�Ԫ��֮ǰ�ĵ�һ����Ԫ�أ�����Ž�ȥ��������
				{
					if (nums[m] == ' ')
					{
						nums[m] = nums[i];
						tep = nums[i];
						nums[i] = ' ';
						break;
					}
				}
				numsSize++;
			}
		}
		if (i == (len - 2) && nums[len - 1] != ' ')//������һ��Ԫ�ز�Ϊ�գ�����Ž�ǰ��Ŀ�Ԫ����
		{
			for (int m = 0; m < len - 1; m++)
			{
				if (nums[m] == ' ')
				{
					nums[m] = nums[len - 1];
					nums[len - 1] = ' ';
					break;
				}
			}
			numsSize++;
		}
	}
	printf("%d\n", numsSize);
	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}

//int main()
//{
//	int a[] = { 1,1,2};
//	int i = 0, j = 0, n = 0, tep = 0, tepj = 0;
//	int len = sizeof(a) / sizeof(a[0]);//����ԭ���鳤��
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = i + 1; j < len; j++)//�жϵ�i����֮���Ƿ������i��Ԫ����ȵ���
//		{
//			if (a[i] == ' ')//�����i��Ԫ���ѱ�����Ϊ�գ�������ѭ��
//				break;
//			if (a[i] == a[j])//����ҵ�һ�����i��Ԫ����ȵ���
//			{
//				tep = a[i];//�ݴ��i��Ԫ��
//				for (int m = 0; m < j; m++)//Ѱ�ұ��ҵ��ĵ�j��Ԫ��֮ǰ�ĵ�һ����Ԫ��
//				{
//					if (a[m] == ' ')
//					{
//						a[m] = a[i];//�����ŵ�ǰ��ĵ�һ����Ԫ����
//						a[i] = ' ';//���õ�i��Ԫ��Ϊ��
//						break;
//					}				
//				}
//				n++;
//				for (j = i + 1; j < len - 1; j++)//Ѱ�Ҳ����õ�i��������������ȵ�Ԫ��
//				{
//					if (tep == a[j])
//						a[j] = ' ';
//				}
//				break;
//			}
//			else if (j == 9)//���û���ҵ����i��Ԫ����ȵ���
//			{
//				for (int m = 0; m < j; m++)//Ѱ�Ҹ�Ԫ��֮ǰ�ĵ�һ����Ԫ�أ�����Ž�ȥ��������
//				{
//					if (a[m] == ' ')
//					{
//						a[m] = a[i];
//						tep = a[i];
//						a[i] = ' ';
//						break;
//					}
//				}
//				n++;
//			}
//		}
//		if (i == (len-2) && a[len-1] != ' ')//������һ��Ԫ�ز�Ϊ�գ�����Ž�ǰ��Ŀ�Ԫ����
//		{
//			for (int m = 0; m < len - 1; m++)
//			{
//				if (a[m] == ' ')
//				{
//					a[m] = a[len - 1];
//					a[len - 1] = ' ';
//					break;
//				}
//			}
//			n++;
//		}
//	}
//	printf("%d\n", n);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//
//int fib(int n,int memo[30])
//{
//	if (n == 0 || n == 1)
//		return n;
//	if (memo[n] == 0)
//	{
//		memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
//	}
//	return memo[n];
//}
//
//int main()
//{
//	int memo[31] = { 0 };//��¼�������쳲�������
//	memo[1] = 1;
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n,memo));
//	return 0;
//}

//int fib(int n)
//{
//	if (n == 0 || n == 1)
//		return n;
//	return fib(n - 2) + fib(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//}

//int fib(int n)
//{
//	int fn = 0;
//	int fib[31] = { 0 };
//	int i = 0, j = 0, sum = 0;
//	for (i = 2; i < sizeof(fib) / sizeof(fib[0]); i++)
//	{
//	    fib[0] = 0;
//	    fib[1] = 1;
//		fib[i] = fib[i - 2] + fib[i - 1];
//	}
//	fn = fib[n];
//	return fn;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//}

//int main()
//{
//    int n = 0;
//    int fn = 0;
//    int fib[31] = { NULL };
//    scanf("%d", &n);
//    int i = 0, j = 0, sum = 0;
//    for (i = 2; i < sizeof(fib) / sizeof(fib[0]); i++)
//    {
//        fib[0] = 0;
//        fib[1] = 1;
//        fib[i] = fib[i - 2] + fib[i - 1];
//    }
//    //for (i = 0; i < sizeof(fib) / sizeof(fib[0]); i++)
//    //{
//    //    printf("%d ", fib[i]);
//    //}
//    printf("%d", fib[n]);
//    return 0;
//}

//int main()
//{
//	int fib[30] = { NULL };
//	printf("%d",sizeof(fib) / sizeof(fib[0]));
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 2; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			sum++;
//			printf("%d ", i);
//		}
//	}
//	printf("%d ", sum);
//
//	return 0;
//}