#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class Building;

class Godgay
{
private:
	Building* building;
public:
	Godgay();
	void tect();
};

class Building
{
	friend void Godgay::tect();
public:
	string m_sittingroom;
private:
	string m_bedroom;
public:
	Building();
};

Building::Building()
{
	m_sittingroom = "����";
	m_bedroom = "����";
}

Godgay::Godgay()
{
	building = new Building;
}

void Godgay::tect()
{
	cout << building->m_sittingroom << endl;
	cout << building->m_bedroom << endl;
}

int main()
{
	Godgay p;
	p.tect();
	return 0;
}

//class Building;
//
//class Godgay
//{
//private:
//	Building* building;
//public:
//	Godgay();
//public:
//	void tect();
//};
//
//class Building
//{
//	friend class Godgay;
//public:
//	string m_sittingroom;
//private:
//	string m_bedroom;
//public:
//	Building()
//	{
//		m_sittingroom = "����";
//		m_bedroom = "����";
//	}
//};
//
//Godgay::Godgay()
//{
//	building = new Building;
//}
//
//void Godgay::tect()
//{
//	cout << building->m_sittingroom << endl;
//	cout << building->m_bedroom << endl;
//}
//
//int main()
//{
//	Godgay p;
//	p.tect();
//	return 0;
//}

//class Building
//{
//	friend void Goodgay(Building& building);
//public:
//	string m_sittingroom;
//private:
//	string m_bedroom;
//public:
//	Building()
//	{
//		m_sittingroom = "����";
//		m_bedroom = "����";
//	}
//};
//
//void Goodgay(Building& building)
//{
//	cout << building.m_sittingroom << endl;
//	cout << building.m_bedroom << endl;
//}
//
//int main()
//{
//	Building b1;
//	Goodgay(b1);
//	return 0;
//}

//��һ��
//#include<stdio.h>
//
//int main()
//{
//	double F = 0;
//	double C = 0;
//	printf("�����뻪���¶�����\n");
//	scanf("%lf", &F);
//	C = 5.0 / 9.0 * (F - 32);
//	printf("��Ӧ�����¶���Ϊ��%.2lf\n", C);
//	return 0;
//}

////�ڶ���
//#include<stdio.h>
//
//int main()
//{
//	int minutes = 0;
//	int hours = 0;
//	printf("�������������\n");
//	scanf("%d", &minutes);
//	hours = minutes / 60;
//	minutes = minutes % 60;
//	printf("�������Ϊ��%d:%d\n", hours, minutes);
//	return 0;
//}

//class Phone
//{
//public:
//	string phonename;
//	Phone(string phonename) :phonename(phonename)
//	{
//		cout << "Phone���캯��" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone��������" << endl;
//	}
//};
//
//class People
//{
//public:
//	string name;
//	Phone phone;
//	People(string name, string phonename) :name(name), phone(phonename) 
//	{
//		cout << "People���캯��" << endl;
//	}
//	~People()
//	{
//		cout << "People��������" << endl;
//	}
//	void printf()
//	{
//		cout << name << phone.phonename << endl;
//	}
//};
//
//int main()
//{
//	People p("����", "VIVO");
//	p.printf();
//	return 0;
//}