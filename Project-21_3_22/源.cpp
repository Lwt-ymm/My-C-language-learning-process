#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void print(int val)
{
	cout << val << ' ';
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for_each(v.begin(), v.end(), print);
	return 0;
}

//#define PLAN 0
//#define PAIN 1
//#define DEVELOP 2
//
//class Worker
//{
//public:
//	string m_name;
//	int m_salary;
//};
//
//void makeWorker(vector<Worker>& v)
//{
//	string nameSeed = "ABCDEFGHIJ";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.m_name = "员工";
//		worker.m_name += nameSeed[i];
//		worker.m_salary = rand() % 10001 + 10000;
//		v.push_back(worker);
//	}
//}
//
//void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
//{
//	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		int deptId = rand() % 3;
//		m.insert(make_pair(deptId, *it));
//	}
//	
//}
//
//
//void showWorkerByGroup(multimap<int, Worker>& m)
//{
//	cout << "策划部门：" << endl;
//
//	int sum = m.count(PLAN);
//	int i = 0;
//	for (multimap<int, Worker>::iterator it = m.find(PLAN); it != m.end() && i < sum; it++, i++)
//	{
//		cout << it->second.m_name << ' ' << it->second.m_salary << endl;
//	}
//
//	cout << "美术部门：" << endl;
//	sum = m.count(PAIN);
//	i = 0;
//	for (multimap<int, Worker>::iterator it = m.find(PAIN); it != m.end() && i < sum; it++, i++)
//	{
//		cout << it->second.m_name << ' ' << it->second.m_salary << endl;
//	}
//
//	cout << "研发部门：" << endl;
//	sum = m.count(DEVELOP);
//	i = 0;
//	for (multimap<int, Worker>::iterator it = m.find(DEVELOP); it != m.end() && i < sum; it++, i++)
//	{
//		cout << it->second.m_name << ' ' << it->second.m_salary << endl;
//	}
//}
//
//int main()
//{
//	vector<Worker> vWorker;
//
//	makeWorker(vWorker);
//
//	multimap<int, Worker> mWorker;
//	setGroup(vWorker, mWorker);
//
//	showWorkerByGroup(mWorker);
//
//	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
//	//{
//	//	cout << it->m_name << ' ' << it->m_salary << endl;
//	//}
//
//	return 0;
//}

//class Person
//{
//public:
//	string m_name;
//	int m_age;
//
//	Person(string name, int age);
//};
//
//Person::Person(string name, int age)
//{
//	this->m_name = name;
//	this->m_age = age;
//}
//
//class comparePerson
//{
//public:
//	bool operator()(const Person& p1, const Person& p2) const
//	{
//		return p1.m_age > p2.m_age;
//	}
//};
//
//int main()
//{
//	set<Person,const comparePerson> s;
//	Person p1("P1", 20);
//	Person p2("P2", 10);
//	Person p3("P3", 60);
//	Person p4("P4", 40);
//	Person p5("P5", 30);
//
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	s.insert(p4);
//	s.insert(p5);
//
//	for (set<Person,const comparePerson>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << it->m_name << ' ' << it->m_age << endl;
//	}
//
//	return 0;
//}