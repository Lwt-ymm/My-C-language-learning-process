#pragma once
#include<iostream>

using namespace std;

class Identity
{
public:
	//�����˵� ���麯�� ���������д
	virtual void operMenu() = 0;
	//�û��� ����
	string m_name;
	string m_password;
};