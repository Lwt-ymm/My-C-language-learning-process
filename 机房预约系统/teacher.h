#pragma once
#include"identity.h"
#include"order.h"
#include<vector>

class Teacher :public Identity
{
public:
	int m_id;

	//默认构造
	Teacher();
	//有参构造(编号,姓名，密码)
	Teacher(int id, string name, string password);
	//菜单界面
	virtual void operMenu();
	//查看预约
	void showAllOrder();
	//审核预约
	void validOrder();
};
