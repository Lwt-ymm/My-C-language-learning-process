#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

static void CheckCapacity(struct Contact* con);

void SaveContact(const struct Contact* con)
{
	FILE* pfwrite = fopen("../contact.data", "wb");
	if (pfwrite == NULL)
	{
		printf("SaveContact:%s\n", strerror(errno));
		return;
	}
	
	for (int i = 0; i < con->size; i++)
	{
		fwrite(&(con->information[i]), sizeof(struct People), 1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;

}

static void LoadContact(struct Contact* con)
{
	struct People temp = { 0 };
	FILE* pfread = fopen("../contact.data", "rb");
	if (pfread == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}

	while (fread(&temp, sizeof(struct People), 1, pfread))
	{
		CheckCapacity(con);
		con->information[con->size] = temp;
		con->size++;
	}

	fclose(pfread);
	pfread = NULL;
	system("cls");
}

static void CheckCapacity(struct Contact* con)
{
	if (con->size == con->capacity)
	{
		struct People* ptr = (struct People*)realloc(con->information, (con->capacity + 2) * sizeof(struct People));
		if (ptr == NULL)
		{
			printf("CheckCapacity:%s\n", strerror(errno));
			return;
		}
		con->information = ptr;
		printf("���ݳɹ�\n");
	}
}

static void SortContact(struct Contact* con)
{
	int i = 0, j = 0;
	for (i = 0; i < con->size - 1; i++)
	{
		struct People temp = con->information[i];
		for (j = i + 1; j < con->size; j++)
		{
			if (strcmp(con->information[i].name, con->information[j].name) > 0)
			{
				con->information[i] = con->information[j];
				con->information[j] = temp;
			}
		}
	}
}

static int FindByName(const struct Contact* con, char* name)
{
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->information[i].name, name) == 0)
			return i;
	}
	return -1;
}

void InitContact(struct Contact* con)
{
	con->information = (struct People*)malloc(DEFAULT_SIZE * sizeof(struct People));
	if (con->information == NULL)
	{
		printf("InitContact:%s\n", strerror(errno));
		return;
	}
	con->capacity = DEFAULT_SIZE;
	con->size = 0;
	LoadContact(con);
}

void ShowContact(const struct Contact* con)
{
	if (con->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		//���ñ�ͷ
		printf("%-10s\t%-3s\t%-3s\t%-15s\t%-20s\n", "����","�Ա�","����","�绰","סַ");
		for (int i = 0; i < con->size; i++)
		{
			printf("%-10s\t%-3s\t%-3d\t%-15s\t%-20s\n",
				con->information[i].name,
				con->information[i].sex,
				con->information[i].age,
				con->information[i].tele,
				con->information[i].address);
		}
	}
}

void AddContact(struct Contact* con)
{
	CheckCapacity(con);

	printf("������Ҫ�����ϵ�˵����֣�");
	scanf("%s", &con->information[con->size].name);
	printf("������Ҫ�����ϵ�˵��Ա�");
	scanf("%s", &con->information[con->size].sex);
	printf("������Ҫ�����ϵ�˵����䣺");
	scanf("%d", &con->information[con->size].age);
	printf("������Ҫ�����ϵ�˵ĵ绰��");
	scanf("%s", &con->information[con->size].tele);
	printf("������Ҫ�����ϵ�˵ĵ�ַ��");
	scanf("%s", &con->information[con->size].address);

	con->size++;

	SortContact(con);
	printf("��ӳɹ�\n");
}

void DeleteContact(struct Contact* con)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ������ϵ�˵�������");
	scanf("%s", &name);

	pos = FindByName(con,name);

	if (pos == -1)
		printf("����ϵ�˲�����\n");
	else
	{
		for (int i = pos; i < con->size; i++)
		{
			con->information[i] = con->information[i + 1];
		}
		con->size--;
		printf("ɾ���ɹ�\n");
	}
}

void ModifyContact(struct Contact* con)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ĵ���ϵ�˵�������");
	scanf("%s", &name);

	pos = FindByName(con, name);

	printf("�������µ���ϵ�˵����֣�");
	scanf("%s", &con->information[pos].name);
	printf("�������µ���ϵ�˵��Ա�");
	scanf("%s", &con->information[pos].sex);
	printf("�������µ���ϵ�˵����䣺");
	scanf("%d", &con->information[pos].age);
	printf("�������µ���ϵ�˵ĵ绰��");
	scanf("%s", &con->information[pos].tele);
	printf("�������µ���ϵ�˵ĵ�ַ��");
	scanf("%s", &con->information[pos].address);

	SortContact(con);
	printf("���ĳɹ�\n");
}

void SearchContact(const struct Contact* con)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("������Ҫ���ҵ���ϵ�˵�������");
	scanf("%s", &name);

	pos = FindByName(con, name);

	if (pos == -1)
		printf("����ϵ�˲�����\n");
	else
	{
		printf("%-10s\t%-3s\t%-3s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-10s\t%-3s\t%-3d\t%-15s\t%-20s\n",
			con->information[pos].name,
			con->information[pos].sex,
			con->information[pos].age,
			con->information[pos].tele,
			con->information[pos].address);
	}
}