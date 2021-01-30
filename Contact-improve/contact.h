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
	int capacity;//��¼ͨѶ¼��ǰ����
	int size;//��¼ͨѶ¼����ϵ�˸���
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* con);
//��ӡ��ϵ����Ϣ
void ShowContact(const struct Contact* con);
//�����ϵ����Ϣ
void AddContact(struct Contact* con);
//ɾ����ϵ����Ϣ
void DeleteContact(struct Contact* con);
//������ϵ����Ϣ
void ModifyContact(struct Contact* con);
//������ϵ����Ϣ
void SearchContact(const struct Contact* con);
//������ϵ����Ϣ
void SaveContact(const struct Contact* con);