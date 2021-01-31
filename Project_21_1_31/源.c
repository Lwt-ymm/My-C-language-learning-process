#pragma warning (disable : 6031)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

struct Student
{
	char name[20];
	int number;
	struct Student* pnext;
};

struct Student* Create(int* iCount)
{
	struct Student* head = NULL;
	struct Student* end = NULL;
	struct Student* new = NULL;
	*iCount = 0;
	end = new = (struct Student*)malloc(sizeof(struct Student));
	if (end == NULL)
	{
		perror("line24");
		return 0;
	}
	printf("请输入第一个学生的姓名和学号：\n");
	scanf("%s", &(new->name));
	scanf("%d", &(new->number));
	while (new->number != 0)
	{
		(*iCount)++;
		if (*iCount == 1)
		{
			new->pnext = NULL;
			end = new;
			head = new;
		}
		else
		{
			new->pnext = NULL;
			end->pnext = new;
			end = new;
		}
		new = (struct Student*)malloc(sizeof(struct Student));
		if (new == NULL)
		{
			perror("line48");
			return 0;
		}
		scanf("%s", &(new->name));
		scanf("%d", &(new->number));
	}
	free(new);
	new = NULL;
	return head;
}

struct Student* Insert(struct Student* head, int* iCount)
{
	struct Student* new = (struct Student*)malloc(sizeof(struct Student*));
	if (new == NULL)
	{
		perror("line65");
		return 0;
	}
	printf("---------在最前面插入一个成员------------");
	scanf("%s", &(new->name));
	scanf("%d", &(new->number));
	new->pnext = head;
	head = new;
	(*iCount)++;
	return head;
}

void Delete(struct Student* head, int del, int* iCount)
{
	int i = 0;;
	struct Student* temp = NULL, * before = NULL;
	temp = head;
	before = temp;
	printf("------------------删除第 %d 个成员-------------------");
	for (i = 1; i < del; i++)
	{
		before = temp;
		temp = temp->pnext;
	}
	before->pnext = temp->pnext;
	free(temp);
	temp = NULL;
	(*iCount)--;
}

void Print(struct Student* head,int iCount)
{
	struct Student* temp = NULL;
	int num = 1;
	printf("-------------该链表一共有 %d 个成员：--------------\n", iCount);
	temp = head;
	while (temp != NULL)
	{
		printf("第 %d 个成员：\n", num);
		printf("姓名：%s\n", temp->name);
		printf("学号：%d\n", temp->number);
		temp = temp->pnext;
		num++;
	}
}

int main()
{
	int iCount = 0;
	struct Student* head = Create(&iCount);
	head = Insert(head, &iCount);
	Delete(head, 2, &iCount);
	Print(head, iCount);
	return 0;
}

//int Statistics(char* sentence)//定义获得句子单词数的函数
//{
//	int num = 0;
//	for (int i = 0; i < strlen(sentence); i++)
//	{
//		if (sentence[i] != ' ')
//		{
//			num++;
//		}
//	}
//	return num;
//}
//
//int main()
//{
//	char sentence[100] = { 0 };
//	int num = 0;//表示句子中单词个数。
//	printf("请输入一个英文句子：\n");
//	gets(sentence);//获取英文句子。
//	num = Statistics(sentence);//使用Statistics函数获取单词个数的值。
//	printf("该句子中的单词个数为%d个。", num);
//}

//int main()
//{
//	FILE* pf = fopen("../../text.txt", "r");
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	//fputc('b', pf);
//	//fputc('i', pf);
//	//fputc('t', pf);
//
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct Stu
//{
//	int a;
//	int arr[];
//};
//
//int main()
//{
//	struct Stu* ps = (struct Stu*)malloc(24);
//
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	ps->a = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct Stu* ps2 = (struct Stu*)realloc(ps,44);
//
//	if (ps2 == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//		ps = ps2;
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	//int* p = (int*)calloc(10,sizeof(int) =);
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}