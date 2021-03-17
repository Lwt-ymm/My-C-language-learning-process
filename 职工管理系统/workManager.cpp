#include"workManager.h"
#include<string>
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		this->m_empnum = 0;
		this->m_emparr = NULL;
		ifs.close();
		return;
	}

	char ch = 0;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		this->m_empnum = 0;
		this->m_emparr = NULL;
		ifs.close();
		return;
	}

	this->m_empnum = this->get_num();
	this->m_emparr = new Worker * [this->m_empnum];
	this->initEmployee();
	this->isFileEmpty = false;
}

WorkManager::~WorkManager()
{
	delete[] this->m_emparr;
	this->m_emparr = NULL;
}

void WorkManager::showMenu()
{
	cout << "*********************************" << endl;
	cout << "****** ��ӭʹ��ְ������ϵͳ *****" << endl;
	cout << "********* 1.����ְ����Ϣ ********" << endl;
	cout << "********* 2.��ʾְ����Ϣ ********" << endl;
	cout << "********* 3.ɾ����ְְ�� ********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ ********" << endl;
	cout << "********* 5.����ְ����Ϣ ********" << endl;
	cout << "********* 6.���ձ������ ********" << endl;
	cout << "********* 7.��������ĵ� ********" << endl;
	cout << "********* 0.�˳�����ϵͳ ********" << endl;
	cout << "*********************************" << endl;
}

void WorkManager::addEmployee()
{
	cout << "������Ҫ����ְ����������" << endl;

	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		int newsize = this->m_empnum + addnum;
		Worker** newspace = new Worker * [newsize];
		if (this->m_emparr != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparr[i];
			}
		}

		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int deptid;
			cout << "�������" << i + 1 << "��Ա���ı�ţ�" << endl;
			while (1)
			{
				cin >> id;
				if (this->fineEmployee(id) != -1)
				{
					cout << "�ı���Ѵ��ڣ�����������" << endl;
				}
				else
					break;
			}
			cout << "�������" << i + 1 << "��Ա����������" << endl;
			cin >> name;
		choice:
			cout << "��ѡ���" << i + 1 << "��Ա����ְλ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> deptid;
			Worker* worker = NULL;
			switch(deptid)
			{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					cout << "ѡ�����,������ѡ��" << endl;
					goto choice;
					break;
			}
			newspace[this->m_empnum + i] = worker;
		}
		delete[] this->m_emparr;
		this->m_emparr = newspace;
		this->m_empnum = newsize;
		cout << "�ɹ����" << addnum << "��ְ����" << endl;
		
		this->save();
		this->isFileEmpty = false;
		
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������󣬷��ز˵�" << endl;
		system("pause");
		system("cls");
	}

}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparr[i]->m_id << " "
			<< this->m_emparr[i]->m_name << " "
			<< this->m_emparr[i]->m_deptid << endl;
	}

	ofs.close();
}

int WorkManager::get_num()
{
	string worker;

	int num = 0;

	ifstream ifs;

	ifs.open(FILENAME, ios::in);
	while (getline(ifs, worker))
	{
		num++;
	}
	return num;
}

void WorkManager::initEmployee()
{
	int id = 0;
	string name;
	int did = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		if (did == 1)
			this->m_emparr[i] = new Employee(id, name, did);
		else if (did == 2)
			this->m_emparr[i] = new Manager(id, name, did);
		else if (did == 3)
			this->m_emparr[i] = new Boss(id, name, did);
		i++;
	}

	ifs.close();
}

void WorkManager::showEmployee()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->m_empnum; i++)
	{
		this->m_emparr[i]->showInfo();
	}

	system("pause");
	system("cls");
}

int WorkManager::fineEmployee(int id)
{
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparr[i]->m_id == id)
		{
			return i;
		}
	}
	return -1;
}

void WorkManager::delEmployee()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;

		system("pause");
		system("cls");
	}

	int id = 0;
	cout << "������Ҫɾ��ְ���ı�ţ�" << endl;
	cin >> id;
	int index = this->fineEmployee(id);
	if (index  != -1)
	{
		for (int i = index; i < this->m_empnum - 1; i++)
			this->m_emparr[i] = this->m_emparr[i + 1];
		
		this->m_empnum--;
		this->m_emparr[this->m_empnum] = NULL;

		if (this->m_empnum == 0)
			this->isFileEmpty = true;

		this->save();
		cout << "ɾ���ɹ�" << endl;

	}
	else
		cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;

	system("pause");
	system("cls");

}

void WorkManager::modEmpoyee()
{
	if (this->isFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;

		system("pause");
		system("cls");
	}

	int id = 0;
	cout << "������Ҫ�޸�ְ���ı�ţ�" << endl;
	cin >> id;
	int index = this->fineEmployee(id);
	if (index != -1)
	{
		int id = 0;
		string name;
		int did = 0;

		cout << "�������޸ĺ�ı�ţ�" << endl;
		while (1)
		{
			cin >> id;
			if (this->fineEmployee(id) != -1)
			{
				cout << "�ı���Ѵ��ڣ�����������" << endl;
			}
			else
				break;
		}
		cout << "�������޸ĺ��������" << endl;
		cin >> name;
	choice:
		cout << "��ѡ���޸ĺ��ְλ��" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> did;

		delete this->m_emparr[index];
		switch (did)
		{
		case 1:
			this->m_emparr[index] = new Employee(id, name, 1);
			break;
		case 2:
			this->m_emparr[index] = new Manager(id, name, 2);
			break;
		case 3:
			this->m_emparr[index] = new Boss(id, name, 3);
			break;
		default:
			cout << "ѡ�����,������ѡ��" << endl;
			goto choice;
			break;
		}

		this->save();
		cout << "�޸ĳɹ�" << endl;

	}
	else
		cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;

	system("pause");
	system("cls");
}

void WorkManager::searchEmployee()
{
	int choice = 0;
	cout << "��ѡ����ҷ�ʽ��" << endl;
	while (1)
	{
		cout << "1������Ų���" << endl;
		cout << "2������������" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int id = 0;
			cout << "������Ҫ���ҵı�ţ�" << endl;
			cin >> id;
			int temp = this->fineEmployee(id);
			
			if (temp != -1)
				this->m_emparr[temp]->showInfo();
			else
				cout << "û�д���" << endl;
			
			system("pause");
			system("cls");
			break;
		}
		else if (choice == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�������" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparr[i]->m_name == name)
				{
					this->m_emparr[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "û�д���" << endl;
			}

			system("pause");
			system("cls");
			break;
		}
		else
			cout << "ѡ�����������ѡ��" << endl;
	}
}

void WorkManager::sortEmployee()
{
	int choice = 0;
	while (1)
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1���������������" << endl;
		cout << "2������Ž�������" << endl;
		cin >> choice;

		if (choice == 1)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				for (int j = this->m_empnum - 1; j > i; j--)
				{
					if (this->m_emparr[j]->m_id < this->m_emparr[j - 1]->m_id)
					{
						Worker* temp = this->m_emparr[j];
						this->m_emparr[j] = this->m_emparr[j - 1];
						this->m_emparr[j - 1] = temp;
					}
				}
			}

			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				for (int j = this->m_empnum - 1; j > i; j--)
				{
					if (this->m_emparr[j]->m_id > this->m_emparr[j - 1]->m_id)
					{
						Worker* temp = this->m_emparr[j];
						this->m_emparr[j] = this->m_emparr[j - 1];
						this->m_emparr[j - 1] = temp;
					}
				}
			}

			cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
			cout << "ѡ�����������ѡ��" << endl;
	}
}

void WorkManager::cleanFile()
{
	string select;
	while (1)
	{
		cout << "������������룺ȷ��" << endl;
		cout << "����ʧ�������룺����" << endl;
		cin >> select;

		if (select == "ȷ��")
		{
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			if (this->m_emparr != NULL)
			{
				for (int i = 0; i < this->m_empnum; i++)
				{
					delete this->m_emparr[i];
					m_emparr[i] = NULL;
				}
				this->m_empnum = 0;
				delete[] this->m_emparr;
				this->m_emparr = NULL;
				this->isFileEmpty = true;
			}

			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == "����")
		{
			cout << "�������˵�" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
			cout << "�����������������" << endl;
	}
}

void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}