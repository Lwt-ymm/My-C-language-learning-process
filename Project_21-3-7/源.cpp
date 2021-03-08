#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

struct student
{
	string name;
	int score;
};

struct teacher
{
	string name;
	student stu[2];
};

void download(teacher* tea, int len)
{
	//给三位老师赋值
	for (int i = 0; i < len; i++)
	{
		cout << "请输入第" << i + 1 << "个老师的姓名" << endl;
		cin >> tea[i].name;
		//给每位老师的五个学生赋值
		for (int j = 0; j < 2; j++)
		{
			cout << "请输入第" << j + 1 << "个学生的姓名" << endl;
			cin >> tea[i].stu[j].name;
			cout << "请输入第" << j + 1 << "个学生的分数" << endl;
			cin >> tea[i].stu[j].score;
		}
	}
}

int main()
{
	teacher tea[3] = { };
	int len = sizeof(tea) / sizeof(tea[1]);
	download(tea, len);
	for (int i = 0; i < len; i++)
	{
		cout << "第" << i + 1 << "个老师的姓名：";
		cout << tea[i].name << endl;
		for (int j = 0; j < 2; j++)
		{
			cout << tea[i].stu[j].name << endl;
			cout << tea[i].stu[j].score <<endl;
		}
	}
	return 0;
}

//int main()
//{
//	int* p = NULL;
//	cout << sizeof(p) << endl;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 2,4,6,1,9,8,7,5,0,3 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < len; i++)
//	{
//		printf("arr[%d]=%d\n", i, arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int start = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int end = len - 1;
//	for (; start < end; start++, end--)
//	{
//		int temp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = temp;
//	}
//	for (int i = 0; i < len; i++)
//		cout << "arr[" << i << "]=" << arr[i] << endl;
//	return 0;
//}

//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//			cout << i << '*' << j << '=' << setw(2) << setfill(' ') << i * j << ' ';
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 100; i < 1000; i++)
//	{
//		int a = i % 10;
//		int b = i / 10 % 10;
//		int c = i / 100;
//		if (a * a * a + b * b * b + c * c * c == i)
//		{
//			cout << i <<' ';
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0, b = 0, c = 0;
//	cin >> a >> b >> c;
//	cout << a << b << c << endl;
//	if (a > b)
//	{
//		if (a > c)
//			cout << "a" << endl;
//		else
//			cout << "c" << endl;
//	}
//	else
//	{
//		if (b > c)
//			cout << "b" << endl;
//		else
//			cout << "c" << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string a = "abcdef";
//	int len = a.size();
//	cout << a.size() << endl;
//	return 0;
//}

//int main()
//{
//	float a = 3.1415926;
//	double b = 3.1415926;
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//int main()
//{
//	int a[] = { 0,1,2,4,3,5,8,6,9,10 };
//	int b[] = { 0,1,3,2,4,6,5,7,8,9,10 };
//	int i = 0;
//	int alen = sizeof(a) / sizeof(int);
//	int blen = sizeof(b) / sizeof(int);
//	int asum = 0, bsum = 0;
//	int n = 0;
//	for (i = 0; i < alen; i++)
//	{
//		asum ^= a[i];
//	}
//	for (i = 0; i < blen; i++)
//	{
//		bsum ^= b[i];
//	}
//	n = bsum ^ asum;
//	printf("%d\n", n);
//	return 0;
//}

//int main()
//{
//	int a[] = { 0,1,2,4,3,5,8,6,9,10 };
//	int b[] = { 0,1,3,2,4,6,5,7,8,9,10 };
//	int i = 0;
//	int alen = sizeof(a) / sizeof(int);
//	int blen = sizeof(b) / sizeof(int);
//	int asum = 0, bsum = 0;
//	int n = 0;
//	for (i = 0; i < alen; i++)
//	{
//		asum += a[i];
//	}
//	for (i = 0; i < blen; i++)
//	{
//		bsum += b[i];
//	}
//	n = bsum - asum;
//	printf("%d\n", n);
//	return 0;
//}

//#include<stdio.h>
//using namespace std;
//
//int main()
//{
//	int x = 2;
//	double y = 5.4;
//	cout << y / x << endl;
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	double y = 5.4;
//	printf("%lf", (y / x));
//	return 0;
//}