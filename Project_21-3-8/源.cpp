#include<iostream>

using namespace std;

class Person
{
private:
	int A, B, C;
public:
	//Person(int a, int b, int c)
	//{
	//	A = a;
	//	B = b;
	//	C = c;
	//}
	Person(int a, int b, int c) :A(a), B(b), C(c) {};
	void printf()
	{
		cout << A << endl << B << endl << C << endl;
	}
};

int main()
{
	Person p1(10, 20, 30);
	p1.printf();
	return 0;
}

//class Person
//{
//public:
//	//���캯��
//	//1.�޲Σ�Ĭ�ϣ�����
//	Person()
//	{
//		age = 10;
//		cout << "�޲Σ�Ĭ�ϣ����캯������" << endl;
//	}
//	//2.�вι���
//	Person(int a)
//	{
//		age = a;
//		cout << "�вι��캯������" << endl;
//	}
//	//3.��������
//	Person(const Person &p)
//	{
//		age = p.age;
//		cout << "�������캯������" << endl;
//	}
//	//��������
//	~Person()
//	{
//		cout << "������������" << endl;
//	}
//private:
//	int age;
//};
//
//void tect()
//{
//	//���÷�ʽ
//	//1.���ŷ�
//	//Person p1;
//	//Person p2(10);
//	//Person p3(p2);
//	//2.��ʾ��
//	//Person p1;
//	//Person p2 = Person(10);
//	//Person p3 = Person(p3);
//	//3.��ʽת����
//	Person p1;
//	Person p2 = 10;
//	Person p3 = p3;
//}
//
//int main()
//{
//	tect();
//	return 0;
//}

//class Person
//{
//public:
//	Person()
//	{
//		cout << "���캯��" << endl;
//	}
//	~Person()
//	{
//		cout << "��������" << endl;
//	}
//};
//
//void test()
//{
//	Person p;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//class Circle
//{
//private:
//	int r;
//	Point center;
//public:
//	void set_center(Point &p)
//	{
//		center = p;
//	}
//	int get_r()
//	{
//		return r;
//	}
//	Point get_center()
//	{
//		return center;
//	}
//};
//
//class Point
//{
//private:
//	int x, y;
//public:
//	void set_xy(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//	int get_x()
//	{
//		return x;
//	}
//	int get_y()
//	{
//		return y;
//	}
//};
//
//void is_in_circle(Circle &c,Point &p)
//{
//	int x_distance = c.get_center().get_x() - p.get_x();
//	int y_distance = c.get_center().get_y() - p.get_y();
//	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
//	if (distance > c.get_r())
//		cout << "����Բ��" << endl;
//	else if (distance < c.get_r())
//		cout << "����Բ��" << endl;
//	else if (distance = c.get_r())
//		cout << "����Բ��" << endl;
//}
//
//int main()
//{
//	Circle c;
//	Point p, center;
//	p.set_xy(1, 1);
//	center.set_xy(0, 0);
//	c.set_center(center);
//	is_in_circle(c,p);
//	return 0;
//}

//class Cube
//{
//private:
//	int l, w, h;
//public:
//	void setlwh(int a, int b, int c)
//	{
//		l = a;
//		w = b;
//		h = c;
//	}
//	void surface()
//	{
//		cout << 2 * (l * w + l * h + w * h) << endl;
//	}
//	void volume()
//	{
//		cout << l * w * h <<endl;
//	}
//};
//
//int main()
//{
//	Cube c1;
//	c1.setlwh(10, 10, 10);
//	c1.surface();
//	c1.volume();
//	return 0;
//}

//class Student
//{
//public:
//	string name;
//	int number;
//	void assignment()
//	{
//		cin >> name >> number;
//	}
//	void print()
//	{
//		cout << name << ' ' << number;
//	}
//};
//
//int main()
//{
//	Student s1;
//	s1.assignment();
//	s1.print();
//	return 0;
//}

//const double PI = 3.14;
//
//class Circle
//{
//public:
//	int r;
//	double circumference()
//	{
//		return 2 * PI * r;
//	}
//};
//
//int main()
//{
//	Circle c1 = { 10 };
//	cout << c1.circumference() << endl;
//	return 0;
//}

//int main()
//{
//	int* p = new int(10);
//	int*& q = p;
//	delete p;
//	int* arr = new int[10];
//	delete[] arr;
//	return 0;
//}