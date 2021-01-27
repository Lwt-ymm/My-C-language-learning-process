#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<string.h>

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char*)p1;
	if (*p2 == '\n')
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\n')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}

//int my_strcmp(const char* dest, const char* str)
//{
//	assert(dest && str);
//	while (*dest == *str)
//	{
//		if (*dest == '\0')
//			return 0;
//		dest++;
//		str++;
//	}
//	if (*dest > *str)
//		return 1;
//	else
//		return -1;
//}
//
//int main()
//{
//	char arr1[] = { "abcdef" };
//	char arr2[] = { "abcdef" };
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "asd";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//int findnum(int arr[3][3], int* px, int* py, int k)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x <= *px && y >= 0)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int x = 3;
//	int y = 3;
//	int num = 0;
//	printf("请输入要寻找的数：\n");
//	scanf("%d", &num);
//	int ret = findnum(arr, &x, &y, num);
//	if (ret == 1)
//	{
//		printf("找到了：arr[%d][%d] = %d\n", x, y, num);
//	}
//	else
//		printf("该数不存在\n");
//	return 0;
//}

//int is_left_move(char* str1, char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	strncat(str1, str1, len1);
//	char* ret = strstr(str1, str2);
//	if (ret != NULL)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr1[30] = { "ABCDEF" };
//	char arr2[] = { "CDEFAB" };
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}

//////1.暴力左旋法
////void left_move(char* arr, int k)
////{
////	assert(arr != NULL);
////	int len = strlen(arr);
////	assert(k <= len);
////	int i = 0;
////	for (i = 0; i < k; i++)
////	{
////		int j = 0;
////		char temp = *arr;
////		for (j = 0; j < len - 1; j++)
////		{
////			*(arr + j) = *(arr + j + 1);
////		}
////		*(arr + len - 1) = temp;
////	}
////}
//
////2.三步翻转法
//void reverse(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(left != NULL);
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	int len = strlen(arr);
//	reverse(arr, arr + k - 1);//翻转左边CBADEF
//	reverse(arr + k, arr + len - 1);//翻转右边CBAFED
//	reverse(arr, arr + len - 1);//整体翻转DEFABC
//}
//
//int main()
//{
//	char arr[] = { "ABCDEF" };
//	left_move(arr, 3);
//
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int a[10][10] = { 0 };
//	int i = 0, j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				a[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//			}
//		}
//	}
//	for ( i = 0; i < 10; i++)
//	{
//		int row = i;
//		while (row != 10)
//		{
//			printf(" ");
//			row++;
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}