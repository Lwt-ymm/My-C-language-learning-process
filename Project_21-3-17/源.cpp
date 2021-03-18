#include<iostream>
#include<fstream>

using namespace std;

int main()
{

	return 0;
}

//template<typename T>
//void myswap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	myswap<int>(a, b);
//	swap(a, b);
//	cout << a << ' ' << b << endl;
//	return 0;
//}

//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 10 - 1; j > i; j--)
//		{
//			if (a[j] > a[j - 1])
//			{
//				int temp = a[j];
//				a[j] = a[j - 1];
//				a[j - 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << a[i] << endl;
//	}
//	
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 10 - 1; j > i; j--)
//		{
//			if (a[j] < a[j - 1])
//			{
//				int temp = a[j];
//				a[j] = a[j - 1];
//				a[j - 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << a[i] << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int* p = NULL;
//	int* arr[3] = { 0 };
//	for (int i = 0; i < 3; i++)
//	{
//		p = new int(i);
//		arr[i] = p;
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	a = 1 + (b = c = 3);
//	//cout << a << endl;
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	fstream file;
//	file.open("tect.txt", ios::out);
//	file << 'a' << ' ' << 'b' << endl;
//	file << 'a' << ' ' << 'b' << endl;
//	file << 'a' << ' ' << 'b' << endl;
//	file.close();
//	char a[5] = { 0 };
//	file.open("tect.txt", ios::in);
//	if (!file.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return 0;
//	}
//	while (file >> a)
//	{
//		cout << a ;
//	}
//	cout << a << endl;
//	return 0;
//}

//void bubblesort(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = len - 1; j > 0; j--)
//		{
//			if (arr[j] > arr[j - 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	bubblesort(s, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << s[i] << endl;
//	}
//	return 0;
//}