#include<iostream>

using namespace std;

int main()
{

	return 0;
}

//int main()
//{
//	int a[2][3] = { {1,2,3},{4,5,6} };
//	int b[3][2] = { {6,5},{4,3},{2,1} };
//	int i = 0, j = 0, m = 0, n = 0;
//	for (; i < 2 && m < 3; n++)
//	{
//		if (j > 2)
//		{
//			j = 0;
//			i++;
//		}
//		if (n > 1)
//		{
//			n = 0;
//			m++;
//		}
//		int temp = a[i][j];
//		a[i][j] = b[m][n];
//		b[m][n] = temp;
//		j++;
//	}
//
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			cout << b[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//	for (m = 0; m < 3; m++)
//	{
//		for (n = 0; n < 2; n++)
//		{
//			cout << b[m][n] << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//void test1()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//	ofs << "111111111111111" << endl;
//	ofs << "222222222222222" << endl;
//	ofs << "333333333333333" << endl;
//	ofs.close();
//}
//
//void test2()
//{
//	ifstream ifs;
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	/*char buf[100] = { 0 };*/
//	
//	//while (ifs >> buf)
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//string buf;
//	//while (getline(ifs, buf))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	ifs.close();
//}
//
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}