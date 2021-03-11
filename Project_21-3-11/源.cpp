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
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
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
//		m_sittingroom = "客厅";
//		m_bedroom = "卧室";
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
//		m_sittingroom = "客厅";
//		m_bedroom = "卧室";
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

//第一题
//#include<stdio.h>
//
//int main()
//{
//	double F = 0;
//	double C = 0;
//	printf("请输入华氏温度数：\n");
//	scanf("%lf", &F);
//	C = 5.0 / 9.0 * (F - 32);
//	printf("对应摄氏温度数为：%.2lf\n", C);
//	return 0;
//}

////第二题
//#include<stdio.h>
//
//int main()
//{
//	int minutes = 0;
//	int hours = 0;
//	printf("请输入分钟数：\n");
//	scanf("%d", &minutes);
//	hours = minutes / 60;
//	minutes = minutes % 60;
//	printf("换算完成为：%d:%d\n", hours, minutes);
//	return 0;
//}

//class Phone
//{
//public:
//	string phonename;
//	Phone(string phonename) :phonename(phonename)
//	{
//		cout << "Phone构造函数" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone解析函数" << endl;
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
//		cout << "People构造函数" << endl;
//	}
//	~People()
//	{
//		cout << "People析构函数" << endl;
//	}
//	void printf()
//	{
//		cout << name << phone.phonename << endl;
//	}
//};
//
//int main()
//{
//	People p("张三", "VIVO");
//	p.printf();
//	return 0;
//}