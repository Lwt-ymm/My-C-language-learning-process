#pragma once
#include"identity.h"
#include"order.h"
#include<vector>

class Teacher :public Identity
{
public:
	int m_id;

	//Ĭ�Ϲ���
	Teacher();
	//�вι���(���,����������)
	Teacher(int id, string name, string password);
	//�˵�����
	virtual void operMenu();
	//�鿴ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
};
