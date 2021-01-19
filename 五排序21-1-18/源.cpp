#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	int nums[] = { 1,1,2 };
	int numsSize = 0;
	int i = 0, j = 0, tep = 0;
	int len = sizeof(nums) / sizeof(nums[0]);//计算原数组长度
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)//判断第i个数之后是否有与第i个元素相等的数
		{
			if (nums[i] == ' ')//如果第i个元素已被重置为空，则跳出循环
				break;
			if (nums[i] == nums[j])//如果找到一个与第i个元素相等的数
			{
				tep = nums[i];//暂存第i个元素
				for (int m = 0; m < j; m++)//寻找被找到的第j个元素之前的第一个空元素
				{
					if (nums[m] == ' ')
					{
						nums[m] = nums[i];//把它放到前面的第一个空元素中
						nums[i] = ' ';//重置第i个元素为空
						break;
					}
				}
				numsSize++;
				for (j = i + 1; j < len - 1; j++)//寻找并重置第i个数后面与其相等的元素
				{
					if (tep == nums[j])
						nums[j] = ' ';
				}
				break;
			}
			else if (j == 9)//如果没有找到与第i个元素相等的数
			{
				for (int m = 0; m < j; m++)//寻找该元素之前的第一个空元素，将其放进去，并重置
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
		if (i == (len - 2) && nums[len - 1] != ' ')//如果最后一个元素不为空，将其放进前面的空元素中
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
//	int len = sizeof(a) / sizeof(a[0]);//计算原数组长度
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = i + 1; j < len; j++)//判断第i个数之后是否有与第i个元素相等的数
//		{
//			if (a[i] == ' ')//如果第i个元素已被重置为空，则跳出循环
//				break;
//			if (a[i] == a[j])//如果找到一个与第i个元素相等的数
//			{
//				tep = a[i];//暂存第i个元素
//				for (int m = 0; m < j; m++)//寻找被找到的第j个元素之前的第一个空元素
//				{
//					if (a[m] == ' ')
//					{
//						a[m] = a[i];//把它放到前面的第一个空元素中
//						a[i] = ' ';//重置第i个元素为空
//						break;
//					}				
//				}
//				n++;
//				for (j = i + 1; j < len - 1; j++)//寻找并重置第i个数后面与其相等的元素
//				{
//					if (tep == a[j])
//						a[j] = ' ';
//				}
//				break;
//			}
//			else if (j == 9)//如果没有找到与第i个元素相等的数
//			{
//				for (int m = 0; m < j; m++)//寻找该元素之前的第一个空元素，将其放进去，并重置
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
//		if (i == (len-2) && a[len-1] != ' ')//如果最后一个元素不为空，将其放进前面的空元素中
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
//	int memo[31] = { 0 };//记录计算过得斐波那契数
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