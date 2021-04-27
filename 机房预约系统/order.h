#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include"globalFile.h"


using namespace std;

class Order
{
public:
	//预约条数
	int m_size;
	//存储预约容器
	map<int, map<string, string>> m_orderData;

	//构造函数
	Order();
	//更新预约记录
	void updateOrder();
};