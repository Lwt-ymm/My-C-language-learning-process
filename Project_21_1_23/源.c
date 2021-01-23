#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



////void bubble_sort(int* arr, int sz)
////{
////	int i = 0, j = 0;
////	for (i = 0; i < sz - 1; i++)
////	{
////		for (j = 0; j < sz - 1 - i; j++)
////		{
////			if (arr[j] > arr[j + 1])
////			{
////				int temp = arr[j];
////				arr[j] = arr[j + 1];
////				arr[j + 1] = temp;
////			}
////		}
////	}
////}
//
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(void* base, int sz, int width, int (*comp)(void* emel1, void* emel2))
//{
//	int i = 0, j = 0;
//	for (i = 0; i < sz; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (comp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//struct Stu
//{
//	char name[10];
//	int age;
//};
//
//int compare(const void* elem1, const void* elem2)
//{
//	return strcmp(((struct Stu*)elem1)->name, ((struct Stu*)elem2)->name);
//}
//
//int main()
//{
//	//int a[] = { 1,2,3,4,5,6,7,8,9,0 };
//	//int sz = sizeof(a) / sizeof(a[0]);
//	//bubble_sort(a,sz);
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",30} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	int (*pf)(const void*, const void*) = &compare;
//	bubble_sort(s,sz,sizeof(s[0]),pf);
//	//qsort(s, sz, sizeof(s[0]), pf);
//	//第一个参数：待排序数组的首元素地址
//	//第二个参数：待排序数组的元素个数
//	//第三个参数：待排序数组的每个元素的大小，单位字节
//	//第四个参数：是函数指针，比较两个元素所用函数的地址，这个函数由使用者自己实现
//	//			  函数指针的两个参数是：待比较的两个元素的地址
//
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", a[i]);
//	//}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].name);
//	}
//	return 0;
//}

//char* my_strcop(char* dest, const char* src);
////1.写一个函数指针 pf,能够指向my_strcop
//char*(*pf)(char*,const char*) = my_strcop;
////2.写一个函数指针数组 pfArr，能够存放4个my_strcop函数的地址
//char* (*pfArr[4])(char*, const char*);

//int main()
//{
//	void(*add(int,void(*)(int)))(int);
//	return 0;
//}

//void print(char* str)
//{
//	printf("%s\n", str);
//}
//
//int main()
//{
//	void (*p)(char) = print;
//	(*p)("hello");
//	return 0;
//}

//void print1(int a[3][3], int x, int y)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*pa)[3], int x, int y)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", p[i][j]);
//			printf("%d ", *(*(pa + i) + j));
//			printf("%d ", (*(pa + i))[j]);	
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	print1(a,3,3);
//	print2(a,3,3);
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char* (*parr)[5] = &arr;
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0, j = 0;
//	for (i = 0; i < strlen(parr); i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int check_sys()
//{
//	int a = 1;
//	char* pa = (char*)&a;
//	return *pa;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
//
//int main()
//{
//	//段错误
//	const char* p = "abcdef";//const保护该字符串
//	*p = 'w';
//	printf("%s\n", p);
//	return 0;
//}