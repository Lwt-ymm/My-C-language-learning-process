#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s1 = "hello";

	string s2 = s1.substr(1, 3);
	cout << s2 << endl;


	//string s2 = "hello";
	//if (s1.compare(s2) == 0)
	//{
	//	cout << '=' << endl;
	//}

	//for (int i = 0; i < s1.size(); i++)
	//{
	//	//cout << s1[i] << endl;
	//	cout << s1.at(i) << endl;
	//}

	//s1.insert(1, "111");
	//cout << s1 << endl;
	//s1.erase(1, 3);
	//cout << s1 << endl;

	return 0;
}

//int main()
//{
//	string s1 = "abcdef";
//	int pos = s1.find("cd",1);
//	cout << pos << endl;
//	//rfind´ÓÓÒÍù×ó²éÕÒ£¬findÊÇ´Ó×óÍùÓÒÕÒ
//	s1.replace(0, 2, "1111");
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1 = "Hello ";
//	s1 += "World";
//	cout << s1 << endl;
//	string s2 = "AAAA";
//	s1 += s2;
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s1;
//	s1.assign("Hello World");
//	cout << s1 << endl;
//
//	string s2;
//	s2.assign(s1, 0,5);
//	cout << s2 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//
//	//const char* str = "Hello World";
//	//string s2(str);
//	string s2("Hello World");
//	cout << s2 << endl;
//
//	string s3(s2);
//	cout << s3 << endl;
//
//	string s4(10, 'a');
//	cout << s4 << endl;
//
//	return 0;
//}

//void myPrint(int val)
//{
//	cout << val << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//
//	//vector<int>::iterator itBegin = v.begin();
//	//vector<int>::iterator itEnd = v.end();
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//}
//
//	//for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
//	//{
//	//	cout << *it << endl;
//	//}
//
//	for_each(v.begin(), v.end(), myPrint);
//
//	return 0;
//}