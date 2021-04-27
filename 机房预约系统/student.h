#pragma once
#include"identity.h"
#include<vector>
#include"globalFile.h"
#include<fstream>
#include"computerRoom.h"
#include"order.h"
#include<Windows.h>

class Student :public Identity
{
public:
	int m_id;
	//机房容器
	vector<ComputerRoom> vC;

	//默认构造
	Student();
	//有参构造(编号,姓名，密码)
	Student(int id, string name, string password);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
};