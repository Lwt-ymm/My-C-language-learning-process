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
		printf("增容成功\n");
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
		printf("通讯录为空\n");
	else
	{
		//设置标头
		printf("%-10s\t%-3s\t%-3s\t%-15s\t%-20s\n", "姓名","性别","年龄","电话","住址");
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

	printf("请输入要添加联系人的名字：");
	scanf("%s", &con->information[con->size].name);
	printf("请输入要添加联系人的性别：");
	scanf("%s", &con->information[con->size].sex);
	printf("请输入要添加联系人的年龄：");
	scanf("%d", &con->information[con->size].age);
	printf("请输入要添加联系人的电话：");
	scanf("%s", &con->information[con->size].tele);
	printf("请输入要添加联系人的地址：");
	scanf("%s", &con->information[con->size].address);

	con->size++;

	SortContact(con);
	printf("添加成功\n");
}

void DeleteContact(struct Contact* con)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的联系人的姓名：");
	scanf("%s", &name);

	pos = FindByName(con,name);

	if (pos == -1)
		printf("该联系人不存在\n");
	else
	{
		for (int i = pos; i < con->size; i++)
		{
			con->information[i] = con->information[i + 1];
		}
		con->size--;
		printf("删除成功\n");
	}
}

void ModifyContact(struct Contact* con)
{
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入要更改的联系人的姓名：");
	scanf("%s", &name);

	pos = FindByName(con, name);

	printf("请输入新的联系人的名字：");
	scanf("%s", &con->information[pos].name);
	printf("请输入新的联系人的性别：");
	scanf("%s", &con->information[pos].sex);
	printf("请输入新的联系人的年龄：");
	scanf("%d", &con->information[pos].age);
	printf("请输入新的联系人的电话：");
	scanf("%s", &con->information[pos].tele);
	printf("请输入新的联系人的地址：");
	scanf("%s", &con->information[pos].address);

	SortContact(con);
	printf("更改成功\n");
}

void SearchContact(const struct Contact* con)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	printf("请输入要查找的联系人的姓名：");
	scanf("%s", &name);

	pos = FindByName(con, name);

	if (pos == -1)
		printf("该联系人不存在\n");
	else
	{
		printf("%-10s\t%-3s\t%-3s\t%-15s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-10s\t%-3s\t%-3d\t%-15s\t%-20s\n",
			con->information[pos].name,
			con->information[pos].sex,
			con->information[pos].age,
			con->information[pos].tele,
			con->information[pos].address);
	}
}