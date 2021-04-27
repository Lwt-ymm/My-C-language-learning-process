#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<conio.h>

using namespace std;

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�룬��������ָ�������ӿ�
		Manager* man = (Manager*)manager;
		
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)
		{
			man->addPerson();//����˺�
		}
		else if (select == 2)
		{
			man->showPerson();//�鿴�˺�
		}
		else if (select == 3)
		{
			man->showComputer();//�鿴����
		}
		else if (select == 4)
		{
			man->cleanFile();//���ԤԼ
		}
		else
		{
			delete manager;//ע������Ա
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();
		//������ָ��תΪ����ָ�룬��������ָ�������ӿ�
		Student* man = (Student*)student;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)
		{
			man->applyOrder();//����ԤԼ
		}
		else if (select == 2)
		{
			man->showMyOrder();//�鿴�ҵ�ԤԼ
		}
		else if (select == 3)
		{
			man->showAllOrder();//�鿴����ԤԼ
		}
		else if (select == 4)
		{
			man->cancelOrder();//ȡ��ԤԼ
		}
		else
		{
			delete student;//ע��ѧ��
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//����ѧ��ʦ�˵�
		teacher->operMenu();
		//������ָ��תΪ����ָ�룬��������ָ�������ӿ�
		Teacher* man = (Teacher*)teacher;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)
		{
			man->showAllOrder();//�鿴ԤԼ
		}
		else if (select == 2)
		{
			man->validOrder();//���ԤԼ
		}
		else
		{
			delete teacher;//ע����ʦ
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼ ����1�ļ� �������
void loginIn(string fileName, int type)
{
	//����ָ��ָ���������
	Identity* person = NULL;
	
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in); 
	
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string password;

	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	//�������*��
	char temp = 0;
	while (1)
	{
		temp = _getch();
		if (temp == 13)
		{
			cout << endl;
			break;
		}
		else if (temp == 8)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			password.pop_back();
		}
		else
		{
			password += temp;
			cout << "*";
		}
	}

	//�����֤
	if (type == 1)//ѧ��
	{
		//׼�������ļ���Ϣ
		int fid = 0;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "ѧ����¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				//����ѧ�����Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)//��ʦ
	{
		//׼�������ļ���Ϣ
		int fid = 0;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "��ʦ��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//�����ʦ���Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)//����Ա
	{
		//׼�������ļ���Ϣ
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				cout << "����Ա��ʦ��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				//�������Ա���Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	while (1)
	{
		cout << "=======================��ӭʹ�û���ԤԼϵͳ=======================" << endl;
		cout << "��ѡ��������ݣ�" << endl;
		cout << "\t\t ------------------------------ " << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          1.ѧ    ��          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          2.��    ʦ          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          3.�� �� Ա          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          0.��    ��          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t ------------------------------ " << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�á�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			break;
		}
	}

	return 0;
}