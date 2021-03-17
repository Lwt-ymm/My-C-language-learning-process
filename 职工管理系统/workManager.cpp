#include"workManager.h"
#include<string>
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//文件不存在
	{
		this->m_empnum = 0;
		this->m_emparr = NULL;
		ifs.close();
		return;
	}

	char ch = 0;
	ifs >> ch;
	if (ifs.eof())//文件为空
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
	cout << "****** 欢迎使用职工管理系统 *****" << endl;
	cout << "********* 1.增加职工信息 ********" << endl;
	cout << "********* 2.显示职工信息 ********" << endl;
	cout << "********* 3.删除离职职工 ********" << endl;
	cout << "********* 4.修改职工信息 ********" << endl;
	cout << "********* 5.查找职工信息 ********" << endl;
	cout << "********* 6.按照编号排序 ********" << endl;
	cout << "********* 7.清空所有文档 ********" << endl;
	cout << "********* 0.退出管理系统 ********" << endl;
	cout << "*********************************" << endl;
}

void WorkManager::addEmployee()
{
	cout << "请输入要增加职工的数量：" << endl;

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
			cout << "请输入第" << i + 1 << "个员工的编号：" << endl;
			while (1)
			{
				cin >> id;
				if (this->fineEmployee(id) != -1)
				{
					cout << "改编号已存在，请重新输入" << endl;
				}
				else
					break;
			}
			cout << "请输入第" << i + 1 << "个员工的姓名：" << endl;
			cin >> name;
		choice:
			cout << "请选择第" << i + 1 << "个员工的职位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
					cout << "选择错误,请重新选择" << endl;
					goto choice;
					break;
			}
			newspace[this->m_empnum + i] = worker;
		}
		delete[] this->m_emparr;
		this->m_emparr = newspace;
		this->m_empnum = newsize;
		cout << "成功添加" << addnum << "个职工。" << endl;
		
		this->save();
		this->isFileEmpty = false;
		
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入错误，返回菜单" << endl;
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
		cout << "文件不存在或记录为空" << endl;
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
		cout << "文件不存在或记录为空" << endl;
		return;

		system("pause");
		system("cls");
	}

	int id = 0;
	cout << "请输入要删除职工的编号：" << endl;
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
		cout << "删除成功" << endl;

	}
	else
		cout << "删除失败，未找到该职工" << endl;

	system("pause");
	system("cls");

}

void WorkManager::modEmpoyee()
{
	if (this->isFileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		return;

		system("pause");
		system("cls");
	}

	int id = 0;
	cout << "请输入要修改职工的编号：" << endl;
	cin >> id;
	int index = this->fineEmployee(id);
	if (index != -1)
	{
		int id = 0;
		string name;
		int did = 0;

		cout << "请输入修改后的编号：" << endl;
		while (1)
		{
			cin >> id;
			if (this->fineEmployee(id) != -1)
			{
				cout << "改编号已存在，请重新输入" << endl;
			}
			else
				break;
		}
		cout << "请输入修改后的姓名：" << endl;
		cin >> name;
	choice:
		cout << "请选择修改后的职位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
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
			cout << "选择错误,请重新选择" << endl;
			goto choice;
			break;
		}

		this->save();
		cout << "修改成功" << endl;

	}
	else
		cout << "修改失败，未找到该职工" << endl;

	system("pause");
	system("cls");
}

void WorkManager::searchEmployee()
{
	int choice = 0;
	cout << "请选择查找方式：" << endl;
	while (1)
	{
		cout << "1、按编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int id = 0;
			cout << "请输入要查找的编号：" << endl;
			cin >> id;
			int temp = this->fineEmployee(id);
			
			if (temp != -1)
				this->m_emparr[temp]->showInfo();
			else
				cout << "没有此人" << endl;
			
			system("pause");
			system("cls");
			break;
		}
		else if (choice == 2)
		{
			string name;
			cout << "请输入要查找的姓名：" << endl;
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
				cout << "没有此人" << endl;
			}

			system("pause");
			system("cls");
			break;
		}
		else
			cout << "选择错误请重新选择" << endl;
	}
}

void WorkManager::sortEmployee()
{
	int choice = 0;
	while (1)
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按编号升序排序" << endl;
		cout << "2、按编号降序排序：" << endl;
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

			cout << "排序完成" << endl;
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

			cout << "排序完成" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
			cout << "选择错误，请重新选择" << endl;
	}
}

void WorkManager::cleanFile()
{
	string select;
	while (1)
	{
		cout << "清空数据请输入：确认" << endl;
		cout << "操作失误请输入：返回" << endl;
		cin >> select;

		if (select == "确认")
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

			cout << "清空数据完成" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == "返回")
		{
			cout << "返回主菜单" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
			cout << "输入错误，请重新输入" << endl;
	}
}

void WorkManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}