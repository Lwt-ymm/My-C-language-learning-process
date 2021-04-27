#include"student.h"

//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���(��ţ�����������)
Student::Student(int id, string name, string password)
{
	this->m_id = id;
	this->m_name = name;
	this->m_password;

	//��ȡ������Ϣ
	ifstream ifs;
	ComputerRoom c;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "������Ϣ�ļ���ʧ��" << endl;
	}

	while (ifs >> c.m_id && ifs >> c.m_max)
	{
		vC.push_back(c);
	}
	ifs.close();
}
//�˵�����
void Student::operMenu()
{
	cout << "=============��ӭѧ��" << this->m_name << "��¼=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.����ԤԼ          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|        2.�鿴�ҵ�ԤԼ        |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|        3.�鿴����ԤԼ        |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          4.ȡ��ԤԼ          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.ע����¼          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}
//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "��ѡ��ҪԤԼ�����ڣ�" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	int data = 0;
	int time = 0;
	int room = 0;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ��ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> time;
		if (time >= 1 && time <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ��ҪԤԼ�Ļ�����" << endl;
	cout << "1�Ż���������" << vC[0].m_max << endl;
	cout << "2�Ż���������" << vC[1].m_max << endl;
	cout << "3�Ż���������" << vC[2].m_max << endl;


	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ�������С���" << endl;

	ofstream ofs(ORDER_FILE, ios::in);

	ofs << "data:" << data << ' ';
	ofs << "time:" << time << ' ';
	ofs << "room:" << room << ' ';
	ofs << "stuid:" << this->m_id << ' ';
	ofs << "stuname:" << this->m_name << ' ';
	ofs << "state:"<< 1 <<endl;

	ofs.close();
	system("pause");
	system("cls");
}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	Order od;
	
	if (od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		if (atoi(od.m_orderData[i]["stuid"].c_str()) == this->m_id)//string->char*��.c_str������->int��atoi��
		{
			cout << "ԤԼ���ڣ���" << od.m_orderData[i]["data"] << ' ';
			cout << "ʱ�Σ�" << (od.m_orderData[i]["time"] == "1" ? "����" : "����") << ' ';
			cout << "������" << od.m_orderData[i]["room"] << ' ';
			string state = "״̬��";//0��ȡ��ԤԼ 1��ԤԼ����� 2��ԤԼ�ɹ� 3��ԤԼʧ��
			if (od.m_orderData[i]["state"] == "0")
			{
				state += "ԤԼ��ȡ��";
			}
			else if (od.m_orderData[i]["state"] == "1")
			{
				state += "ԤԼ�����";
			}
			else if (od.m_orderData[i]["state"] == "2")
			{
				state += "ԤԼ�ɹ�";
			}
			else if (od.m_orderData[i]["state"] == "-1")
			{
				state += "ԤԼʧ��";
			}
			cout << state << endl;
		}
	}

	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showAllOrder()
{
	Order od;

	if (od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << od.m_orderData[i]["data"] << ' ';
		cout << "ʱ�Σ�" << (od.m_orderData[i]["time"] == "1" ? "����" : "����") << ' ';
		cout << "������" << od.m_orderData[i]["room"] << ' ';
		cout << "ѧ�ţ�" << od.m_orderData[i]["stuid"] << ' ';
		cout << "������" << od.m_orderData[i]["stuname"] << ' ';
		string state = "״̬��";//0��ȡ��ԤԼ 1��ԤԼ����� 2��ԤԼ�ɹ� 3��ԤԼʧ��
		if (od.m_orderData[i]["state"] == "0")
		{
			state += "ԤԼ��ȡ��";
		}
		else if (od.m_orderData[i]["state"] == "1")
		{
			state += "ԤԼ�����";
		}
		else if (od.m_orderData[i]["state"] == "2")
		{
			state += "ԤԼ�ɹ�";
		}
		else if (od.m_orderData[i]["state"] == "-1")
		{
			state += "ԤԼʧ��";
		}
		cout << state << endl;
	}

	system("pause");
	system("cls");
}
//ȡ��ԤԼ
void Student::cancelOrder()
{
	cout << "����к�ԤԼ�ɹ����������ɾ����" ;
	int index = 1;
	vector<int> v;
	Order od;

	if (od.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		cout << "pause" << endl;
		cout << "cls" << endl;
		return;
	}
	for (int i = 0; i < od.m_size; i++)
	{
		if (atoi(od.m_orderData[i]["stuid"].c_str()) == this->m_id)//string->char*��.c_str������->int��atoi��
		{
			if (od.m_orderData[i]["state"] == "1" || od.m_orderData[i]["state"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";

				cout << "ԤԼ���ڣ���" << od.m_orderData[i]["data"] << ' ';
				cout << "ʱ�Σ�" << (od.m_orderData[i]["time"] == "1" ? "����" : "����") << ' ';
				cout << "������" << od.m_orderData[i]["room"] << ' ';
				string state = "״̬��";//0��ȡ��ԤԼ 1��ԤԼ����� 2��ԤԼ�ɹ� 3��ԤԼʧ��
				if (od.m_orderData[i]["state"] == "0")
				{
					state += "ԤԼ��ȡ��";
				}
				else if (od.m_orderData[i]["state"] == "1")
				{
					state += "ԤԼ�����";
				}
				else if (od.m_orderData[i]["state"] == "2")
				{
					state += "ԤԼ�ɹ�";
				}
				else if (od.m_orderData[i]["state"] == "-1")
				{
					state += "ԤԼʧ��";
				}
				cout << state << endl;
			}
		}
	}
	cout << "������Ҫɾ����ԤԼ���룬����0���ء�" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				od.m_orderData[v[select] - 1]["state"] == "0";
				od.updateOrder();
				cout << "ԤԼȡ���ɹ���" << endl;
				break;
			}
		}
		cout << "�����������������룺" << endl;
	}

	system("pause");
	system("cls");
}