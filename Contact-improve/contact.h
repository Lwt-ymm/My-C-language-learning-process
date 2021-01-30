#pragma warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_SIZE 3

enum
{
	MAX_NAME = 20,
	MAX_SEX = 5,
	MAX_TELE = 13,
	MAX_ADDRESS = 100
};

enum
{
	Exit,
	Add,
	Delete,
	Search,
	Modify,
	Show,
};

struct People
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
};

struct Contact
{
	struct People* information;
	int capacity;//记录通讯录当前容量
	int size;//记录通讯录中联系人个数
};

//初始化通讯录
void InitContact(struct Contact* con);
//打印联系人信息
void ShowContact(const struct Contact* con);
//添加联系人信息
void AddContact(struct Contact* con);
//删除联系人信息
void DeleteContact(struct Contact* con);
//更改联系人信息
void ModifyContact(struct Contact* con);
//查找联系人信息
void SearchContact(const struct Contact* con);
//保存联系人信息
void SaveContact(const struct Contact* con);