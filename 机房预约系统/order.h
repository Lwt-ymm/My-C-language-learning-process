#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include"globalFile.h"


using namespace std;

class Order
{
public:
	//ԤԼ����
	int m_size;
	//�洢ԤԼ����
	map<int, map<string, string>> m_orderData;

	//���캯��
	Order();
	//����ԤԼ��¼
	void updateOrder();
};