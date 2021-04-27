#pragma once
#include<iostream>

using namespace std;

class Identity
{
public:
	//操作菜单 纯虚函数 子类必须重写
	virtual void operMenu() = 0;
	//用户名 密码
	string m_name;
	string m_password;
};