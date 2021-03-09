//#define

#include<iostream>

using namespace std;

//int main()
//{
//
//	return 0;
//}

int main()
{
	int* p = new int(10);
	int*& q = p;
	delete p;
	int* arr = new int[10];
	delete[] arr;
	return 0;
}