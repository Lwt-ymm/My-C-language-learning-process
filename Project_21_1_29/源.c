#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>



//int check_sys()
//{
//	union un
//	{
//		char c;
//		int a;
//	}u;
//	u.a = 1;
//	return u.c;
//}
//
////int check_sys()
////{
////	int a = 1;
////	int ret = *(char*)&a;
////	return ret;
////}
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

//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//}
//
//struct Student
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	struct Student arr1[] = { {"张三",20},{"李四",30} };
//	struct Student arr2[3] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}

//#include<errno.h>
//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//		printf("%s\n", strerror(errno));
//	else
//		printf("open file success\n");
//	return 0;
//}

//int main()
//{
//	char arr[100] = "961704110@qq.com";
//	char buf[100] = { 0 };
//	strcpy(buf, arr);
//	char* p = "@.";
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}