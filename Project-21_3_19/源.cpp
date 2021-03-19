#include<iostream>
#include<string>
#include"MyArray.hpp"

using namespace std;

int main()
{
	MyArray<int> arr(5);
	for (int i = 0; i < arr.getCapacity(); i++)
	{
		arr.pushBack(i);
	}

	for (int i = 0; i < arr.getCapacity(); i++)
	{
		cout << arr[i] << endl;
	}

	arr.popBack();

	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}

	cout << arr.getCapacity() << endl;
	cout << arr.getSize() << endl;
	return 0;
}

//template<class T1, class T2>
//class Person;
//
//template<class T1, class T2>
//void showPerson(Person<T1, T2>p);
//
//template<class T1, class T2>
//class Person
//{
//	friend void showPerson<>(Person<T1, T2>p);
//	//{
//	//	cout << p.m_name << ' ' << p.m_age << endl;
//	//}
//private:
//	T1 m_name;
//	T2 m_age;
//public:
//	Person(T1 name, T2 age);
//};
//
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//
//template<class T1, class T2>
//void showPerson(Person<T1, T2>p)
//{
//	cout << p.m_name << ' ' << p.m_age << endl;
//}
//
//int main()
//{
//	Person<string, int>p("张三", 18);
//	showPerson(p);
//	return 0;
//}

//template<class T1,class T2>
//class Person
//{
//public:
//	T1 m_name;
//	T2 m_age;
//
//	Person(T1 name, T2 age);
//
//	void showPerson();
//};
//
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << this->m_name << " " << this->m_age << endl;
//}
//
//void test1()
//{
//	Person<string, int>p1("张三", 18);
//	p1.showPerson();
//}
//
//int main()
//{
//	test1();
//	return 0;
//}