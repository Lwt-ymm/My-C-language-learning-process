#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}
//�вι���(���,����������)
Teacher::Teacher(int id, string name, string password)
{
	this->m_id = id;
	this->m_name;
	this->m_password = password;
}
//�˵�����
void Teacher::operMenu()
{
	cout << "=============��ӭ��ʦ" << this->m_name << "��¼=============" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          1.�鿴ԤԼ          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          2.���ԤԼ          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t|          0.ע����¼          |" << endl;
	cout << "\t|                              |" << endl;
	cout << "\t ------------------------------ " << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}
//�鿴ԤԼ
void Teacher::showAllOrder()
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
//���ԤԼ
void Teacher::validOrder()
{
	cout << "����˵��������£�" << endl;
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
		if (od.m_orderData[i]["state"] == "1" )
		{
			v.push_back(i);
			cout << index++ << "��";

			cout << "ԤԼ���ڣ���" << od.m_orderData[i]["data"] << ' ';
			cout << "ʱ�Σ�" << (od.m_orderData[i]["time"] == "1" ? "����" : "����") << ' ';
			cout << "������" << od.m_orderData[i]["room"] << ' ';
			string state = "״̬��";//0��ȡ��ԤԼ 1��ԤԼ����� 2��ԤԼ�ɹ� 3��ԤԼʧ��
		if (od.m_orderData[i]["state"] == "1")
		{
			state += "ԤԼ�����";
		}
			cout << state << endl;
		}
	}
	cout << "������Ҫ���������룬����0���ء�" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					od.m_orderData[v[select] - 1]["state"] == "2";
				}
				else
				{
					od.m_orderData[v[select] - 1]["state"] == "-1";
				}
				od.updateOrder();
				cout << "ԤԼ��˳ɹ���" << endl;
				break;
			}
		}
		cout << "�����������������룺" << endl;
	}

	system("pause");
	system("cls");
}