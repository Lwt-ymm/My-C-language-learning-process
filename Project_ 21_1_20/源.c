#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>



//int my_strlen(const char* a)
//{
//	int count = 0;
//	assert(a != NULL);
//	while (*a != '\0')
//	{
//		count++;
//		a++;
//	}
//	return count;
//}
//
//int main()
//{
//	char a[] = { "abcdef" };
//	int len = 0;
//	len = my_strlen(a);
//	printf("%d", len);
//	return 0;
//}

//#include<assert.h>
//
//char* my_strcop(char* arr1,const char* arr2)
//{
//	int ret = arr1;
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return ret;
//}
//
////void my_strcop(char* arr1, char* arr2)
////{
////	if (*arr1 != NULL && *arr2 != NULL)
////	{
////		while (*arr1++ = *arr2++)
////		{
////			;
////		}
////	}
////}
//
////void my_strcop(char* arr1, char* arr2)
////{
////	while (*arr2 != '\0')
////	{
////		*arr1 = *arr2;
////		arr2++;
////		arr1++;
////	}
////	*arr1 = *arr2;
////}
//
//int main()
//{
//	char arr1[] = { "######################" };
//	char arr2[] = { "bit" };
//	my_strcop(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//typedef struct stu//�������ṹ������
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}stu;//stuҲ���Դ���ṹ��
//
//struct t
//{
//	char a[5];
//	struct stu s;
//	int b;
//};
//
//void print1(stu* ps)//�ṹ�崫�δ���ַ
//{
//	printf("name:%s\n", ps->name);
//}
//
//////struct �ṹ��ؼ��� stu�ṹ���ǩ  struct stu�ṹ������
////struct stu
////{
////	//��Ա����
////	char name[20];
////	short age;
////	char tele[12];
////	char sex[5];
////}s1,s2,s3;//s1,s2,s3��ȫ�ֱ�����һ�㲻��
//
//int main()
//{
//	struct stu s1 = {"����",20,"15215616156","��"};//�ֲ�����
//	struct t t = { "hehe",{"����",20,"15632756485","����"},11 };
//	//printf("%s\n", t.s.name);
//	print1(&s1);
//	return 0;
//}

//void reverse_string(char* arr)
//{
//	char temp = arr[0];
//	int len = strlen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (strlen(arr + 1) >= 2)
//		reverse_string(arr + 1);
//	arr[len - 1] = temp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}