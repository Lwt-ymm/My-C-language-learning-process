#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���(����������)
Manager::Manager(string name, string password)
{
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_password = password;
	//��ʼ����������ȡѧ����ʦ��Ϣ
	this->initVector();

	//��ȡ������Ϣ
	vC.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "������Ϣ�ļ���ʧ��" << endl;
	}
	ComputerRoom c;
	while (ifs >> c.m_id && ifs >> c.m_max)
	{
		vC.push_back(c);
	}
	ifs.close();
}
//�˵�����
void Manager::operMenu()
{
	cout << "=============��ӭ����Ա" << this->m_name << "��¼=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.����˺�          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          2.�鿴�˺�          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          3.�鿴����          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          4.���ԤԼ          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.ע����¼          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "������Ҫ����˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ���˺�" << endl;
	cout << "2����ӽ�ʦ�˺�" << endl;

	string fileName;
	string tip;
	string eor;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		eor = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		eor = "ְ�����ظ�������������";
	}

	int id = 0;
	string name;
	string password;
	while (true)
	{
		cout << tip;
		cin >> id;

		if (this->checkRepeat(id, select))
		{
			cout << eor << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> password;

	ofs.open(fileName, ios::out | ios::app);
	ofs << id << ' ' << name << ' ' << password << endl;
	ofs.close();
	this->initVector();
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
}
//��ӡ��Ϣ
void printfS(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << ' ' << "������" << s.m_name << ' ' << "���룺" << s.m_password << endl;
}
void printfT(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_id << ' ' << "������" << t.m_name << ' ' << "���룺" << t.m_password << endl;
}
void printfC(ComputerRoom& c)
{
	cout << "�����ţ�" << c.m_id << ' ' << "����������" << c.m_max << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ����Ϣ" << endl;
	cout << "2���鿴���н�ʦ��Ϣ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vS.begin(),vS.end(), printfS);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vT.begin(), vT.end(), printfT);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "���л�����Ϣ���£�" << endl;
	for_each(vC.begin(), vC.end(), printfC);
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "���ԤԼ�ɹ�" << endl;
	system("pause");
	system("cls");
}
//��ʼ������
void Manager::initVector()
{
	vS.clear();
	vT.clear();
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs>>s.m_password)
	{
		vS.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_id && ifs >> t.m_name && ifs>>t.m_password)
	{
		vT.push_back(t);
	}
	ifs.close();
}
//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vS.begin(); it != vS.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vT.begin(); it != vT.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	return false;
}