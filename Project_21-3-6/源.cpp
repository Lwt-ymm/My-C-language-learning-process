#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>

//int removeDuplicates(int* nums, int numsSize) {
//    int j = numsSize;
//    if (j > 1) 
//    {
//        j = 1;
//        for (int i = 1; i < numsSize; i++) 
//        {
//            if (nums[i] == nums[i - 1]) 
//            {
//                continue;
//            }
//            else 
//            {
//                nums[j] = nums[i];
//                j++;
//            }
//        }
//    }
//    return j;
//}
//
////int removeDuplicates(int* nums, int numsSize) 
////{
////	for (int i = 0; i < numsSize; i++)
////	{
////		while (nums[i] == nums[i + 1] && i < numsSize)
////		{
////			for (int j = i; j < numsSize - 2; j++)
////			{
////				nums[j + 1] = nums[j + 2];
////			}
////			numsSize--;
////		}
////	}
////	return numsSize+1;
////}
//
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	int len = removeDuplicates(arr, sizeof(arr) / sizeof(int));
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int next[10] = { 0 };
//int data[10] = { 0 };
//
//void add(int ind, int p, int n)
//{
//	next[ind] = p;
//	data[p] = n;
//}
//
//int main()
//{
//	int head = 3;
//	add(3, 4, 1);
//	add(4, 2, 2);
//	add(2, 9, 3);
//	add(9, 6, 4);
//	int p = head;
//	while (p != 0)
//	{
//		printf("%d->", data[p]);
//		p = next[p];
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1, mul = 1, n = 0;
//	scanf("%d", &n);
//	for (;;)
//	{
//		mul = mul * i;
//		if (++i > n)
//		{
//			printf("mul = %d\n", mul);
//			break;
//		}
//	}
//	//while (1)
//	//{
//	//	mul = mul * i;
//	//	if (++i > n)
//	//	{
//	//		printf("mul = %d\n", mul);
//	//		break;
//	//	}
//	//}
//	return 0;
//}

////二分查找
//int BinarySearch(int* arr, int len, int x)
//{
//	assert(arr);
//	
//	int begin = 0, end = len - 1;
//	while (begin <= end)
//	{
//		int mid = (begin + end) >> 1;
//		if (arr[mid] > x)
//			end = mid ;
//		else if (arr[mid] < x)
//			begin = mid + 1;
//		else
//			return mid;
//	}
//
//	return -1;
//}
//
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int len = sizeof(arr) / sizeof(int);
//	int x = 0;
//	scanf("%d", &x);
//	int n = BinarySearch(arr, len, x);
//	if (n != -1)
//		printf("a[%d]=%d\n", n, x);
//	else
//		printf("该数不存在\n");
//	return 0;
//}
//int test()
//{
//	int a = printf("2");
//	return a;
//}
//
//int main()
//{
//	printf("%d", test());
//	return 0;
//}

//void calculate(int a, int b, int c);
//
//int main()
//{
//	int a, b, c;
//	printf("请分别输入长宽高:\n");
//	scanf("%d%d%d", &a, &b, &c);
//	calculate(a, b, c);
//	return 0;
//}
//void calculate(int a, int b, int c)
//{
//	int v;
//	v = a * b * c;
//	printf("长方形体积为:%d\n", v);
//}

////第三题
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d%d", &a, &b);
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d b=%d", a, b);
//	return 0;
//}
//
////第四题
//int main()
//{
//	double a = 0, b = 0, c = 0, s = 0;
//	scanf("%lf%lf", &a, &b);
//	c = sqrt(a * a + b * b);
//	s = a * b;
//	printf("斜边c=%.2lf\n面积s=%.2lf\n",c,s);
//	return 0;
//}