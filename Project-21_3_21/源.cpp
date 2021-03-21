#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<list>
using namespace std;

int main()
{

	return 0;
}

//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	int m_height;
//
//	Person(string name, int age, int height);
//};
//
//Person::Person(string name, int age, int height)
//{
//	this->m_name = name;
//	this->m_age = age;
//	this->m_height = height;
//}
//
//bool comparePerson(Person& p1, Person& p2)
//{
//	if (p1.m_age == p2.m_age)
//	{
//		return p1.m_height > p2.m_height;
//	}
//	else
//	{
//		return p1.m_age < p2.m_age;
//	}
//}
//
//int main()
//{
//	list<Person> l;
//
//	Person p1("P1", 40, 190);
//	Person p2("P2", 45, 170);
//	Person p3("P3", 25, 160);
//	Person p4("P4", 35, 180);
//	Person p5("P5", 25, 150);
//	Person p6("P6", 35, 200);
//
//	l.push_back(p1);
//	l.push_back(p2);
//	l.push_back(p3);
//	l.push_back(p4);
//	l.push_back(p5);
//	l.push_back(p6);
//
//	l.sort(comparePerson);
//
//	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << it->m_name << ' ' << it->m_age << ' ' << it->m_height << endl;
//	}
//
//	return 0;
//}

//class Person
//{
//public:
//	string m_name;
//	int score;
//	
//	Person(string name, int score);
//};
//
//Person::Person(string name, int score)
//{
//	this->m_name = name;
//	this->score = score;
//}
//
//void createPerson(vector<Person>& v)
//{
//	string nameSeed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "Ñ¡ÊÖ";
//		name += nameSeed[i];
//		int score = 0;
//		Person p(name, score);
//		v.push_back(p);
//	}
//}
//
//void setScore(vector<Person>& v)
//{
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		deque<int> d;
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand() % 41 + 60;
//			d.push_back(score);
//		}
//		
//		sort(d.begin(), d.end());
//		d.pop_back();
//		d.pop_front();
//
//		int sum = 0;
//		for (deque<int>::iterator it = d.begin(); it < d.end(); it++)
//		{
//			sum += *it;
//		}
//		int avg = sum / d.size();
//		it->score = avg;
//	}
//}
//
//int main()
//{
//	vector<Person> v;
//	createPerson(v);
//
//	setScore(v);
//
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << (*it).m_name << ' ' << (*it).score << endl;
//	}
//
//	return 0;
//}

//void printVector(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
//	{
//		cout << *it << ' ';
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector <int> v1;
//	v1.push_back(0);
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	printVector(v1);
//
//	v1.pop_back();
//	printVector(v1);
//
//	v1.insert(v1.begin(), 10);
//	printVector(v1);
//
//	v1.insert(v1.begin(), 2, 100);
//	printVector(v1);
//
//	v1.erase(v1.begin());
//	printVector(v1);
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1;
//
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//
//	//vector<int> v2(v1);
//	vector<int> v2(v1.begin(), v1.end());
//	printVector(v1);
//
//	/*printVector(v2);*/
//	cout << v1.capacity() << endl;
//	cout << v1.size() << endl;
//
//
//	return 0;
//}