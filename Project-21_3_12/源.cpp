#include<iostream>

using namespace std;

class Add
{
public:
	int operator()(int a, int b);
};

int Add::operator()(int a, int b)
{
	return a + b;
}

int main()
{
	Add add;
	cout << add(1, 1) << endl;
	cout << Add()(1, 1) << endl;
	return 0;
}

//class Person
//{
//public:
//	int* m_age;
//public:
//	Person(int age);
//	~Person();
//public:
//	Person& operator=(Person& p);
//};
//
//Person::Person(int age)
//{
//	m_age = new int(age);
//}
//
//Person::~Person()
//{
//	if (m_age != NULL)
//	{
//		delete m_age;
//		m_age = NULL;
//	}
//}
//
//Person& Person::operator=(Person& p)
//{
//	if (m_age != NULL)
//	{
//		delete m_age;
//		m_age = NULL;
//	}
//	m_age = new int(*p.m_age);
//	return *this;
//}
//
//int main()
//{
//	Person p1(10), p2(20), p3(30);
//	p3 = p2 = p1;
//	cout << *p1.m_age << endl;
//	cout << *p2.m_age << endl;
//	cout << *p3.m_age << endl;
//	return 0;
//}

//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//private:
//	int myint;
//public:
//	MyInteger();
//	MyInteger& operator++();
//	MyInteger& operator++(int);
//};
//
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << myint.myint << endl;
//	return cout;
//}
//
//MyInteger::MyInteger()
//{
//	myint = 0;
//}
//
//MyInteger& MyInteger::operator++()
//{
//	myint++;
//	return *this;
//}
//
//MyInteger& MyInteger::operator++(int)
//{
//	MyInteger temp;
//	temp = *this;
//	myint++;
//	return temp;
//}
//
//int main()
//{
//	MyInteger myint;
//	//cout << ++(++myint) << endl;
//	cout << myint++ << endl;
//	//cout << myint << endl;
//	return 0;
//}

//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person p);
//private:
//	int m_a;
//	int m_b;
//public:
//	Person();
//};
//
//Person::Person()
//{
//	m_a = 10;
//	m_b = 10;
//}
//
//ostream& operator<<(ostream& cout, Person p)
//{
//	cout << "p.m_a = " << p.m_a << endl;
//	cout << "p.m_b = " << p.m_b << endl;
//	return cout;
//}
//
//int main()
//{
//	Person p;
//	cout << p << endl;
//	return 0;
//}

//class Person
//{
//public:
//	int m_a;
//	int m_b;
//public:
//	Person();
////public:
////	Person operator+(Person& p);
//};
//
//Person::Person()
//{
//	m_a = 10;
//	m_b = 10;
//}
//
////Person Person::operator+(Person& p)
////{
////	Person temp;
////	temp.m_a = this->m_a + p.m_a;
////	temp.m_b = this->m_b + p.m_b;
////	return temp;
////}
//
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_a = p1.m_a + p2.m_a;
//	temp.m_b = p1.m_b + p2.m_b;
//	return temp;
//}
//
//Person operator+(Person& p1, int a)
//{
//	Person temp;
//	temp.m_a = p1.m_a + a;
//	temp.m_b = p1.m_b + a;
//	return temp;
//}
//
//void tect()
//{
//	Person p1, p2, p3, p4;
//	//p3 = p1.operator+(p2);
//	//p3 = p1 + p2;
//	//cout << p3.m_a << endl;
//	//cout << p3.m_b << endl;
//	//p4 = operator+(p1, p2);
//	p4 = p1 + 10;
//	cout << p4.m_a << endl;
//	cout << p4.m_b << endl;
//}
//
//int main()
//{
//	tect();
//	return 0;
//}